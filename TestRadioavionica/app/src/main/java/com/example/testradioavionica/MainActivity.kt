package com.example.testradioavionica

import android.graphics.*
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.util.Log
import android.view.GestureDetector
import android.view.MotionEvent
import android.view.ViewTreeObserver
import android.widget.Toast
import androidx.core.content.ContextCompat
import androidx.core.graphics.drawable.toBitmap
import androidx.recyclerview.widget.LinearLayoutManager
import com.example.testradioavionica.databinding.ActivityMainBinding
import com.example.testradioavionica.entities.MapGeoPoint
import com.example.testradioavionica.entities.MapPoint
import com.example.testradioavionica.entities.MapSize
import java.io.File
import java.io.IOException

class MainActivity : AppCompatActivity() {

    private lateinit var binding: ActivityMainBinding

    private var mapBitmap: Bitmap? = null

    private var handle: Long? = null

    private var currentPoint = MapPoint(0f,0f)

    private var startX = 0f
    private var startY = 0f

    private var height = 0
    private var width = 0

    private val sensitivityFactor = 5f // the bigger, the slower movement; negative changes direction

    private val pointsList = ArrayList<MapGeoPoint>()
    private val adapter = PointAdapter(pointsList)

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)

        binding = ActivityMainBinding.inflate(layoutInflater)
        setContentView(binding.root)

        binding.recyclerView.adapter = adapter
        binding.recyclerView.layoutManager = LinearLayoutManager(this)

        try {
            val pathFile = getFileFromAssets("Luga4.rsw").absolutePath
            initMap(pathFile)
        }
        catch (e: Exception){
            e.printStackTrace()
            Toast.makeText(this,e.message,Toast.LENGTH_LONG).show()
        }
    }

    private fun initMap(path: String){
        handle = openMapFile(path)
        //set and compute sizes when view size is measured
        binding.imageView.viewTreeObserver.addOnGlobalLayoutListener(object: ViewTreeObserver.OnGlobalLayoutListener{
            override fun onGlobalLayout() {
                binding.imageView.viewTreeObserver.removeOnGlobalLayoutListener(this)
                width = binding.imageView.width
                height = binding.imageView.height
                mapBitmap = Bitmap.createBitmap(width,height, Bitmap.Config.RGB_565)
                currentPoint = MapPoint(-width/2.7f,-height/2.7f) // методом подбора выравнивание по центру видимого куска карты
                updateViewport()
                val gestureDetector = GestureDetector(this@MainActivity,object: GestureDetector.SimpleOnGestureListener(){
                    override fun onLongPress(e: MotionEvent) {
                        Log.d("long","long click")
                        val pointX = currentPoint.x + e.x
                        val pointY = currentPoint.y + e.y
                        val geoPoints = mapXYtoGeoWGS84(handle!!, MapPoint(pointX,pointY))
                        pointsList.add(geoPoints)
                        adapter.notifyDataSetChanged()
                        updateViewport()
                    }
                })
                binding.imageView.setOnTouchListener { _, motionEvent ->
                    gestureDetector.onTouchEvent(motionEvent)
                    when(motionEvent.action){
                        MotionEvent.ACTION_DOWN -> {
                            startX = motionEvent.x / sensitivityFactor
                            startY = motionEvent.y / sensitivityFactor
                        }
                        MotionEvent.ACTION_MOVE -> {
                            val newX = startX - motionEvent.x / sensitivityFactor
                            val newY = startY - motionEvent.y / sensitivityFactor
                            currentPoint = MapPoint(currentPoint.x + newX,currentPoint.y + newY)
                            updateViewport()
                        }
                    }
                    true
                }
            }
        })
    }

    private fun updateViewport(){
        val result = renderViewport(handle!!,currentPoint,mapBitmap!!)
        if(result) {
            binding.imageView.setImageBitmap(mapBitmap)
            renderPoints()
        }
        else
            Toast.makeText(this,"Ошибка рендера карты",Toast.LENGTH_LONG).show()
    }

    private fun renderPoints(){
        for(geoPoint in pointsList){
            val mapPoint = mapGeoToXY(handle!!,geoPoint)
            val x = mapPoint.x - currentPoint.x
            val y = mapPoint.y - currentPoint.y
            drawPoint(x,y)
        }
    }

    private fun drawPoint(pointX: Float, pointY: Float){
        val pointDrawable = ContextCompat.getDrawable(this@MainActivity,R.drawable.map_marker)
        val pointBitmap = pointDrawable!!.toBitmap(pointDrawable.intrinsicWidth/10,pointDrawable.intrinsicHeight/10)
        val paint = Paint()
        val canvas = Canvas(mapBitmap!!)
        pointBitmap.density = canvas.density
        Log.d("density", pointBitmap.density.toString())
        canvas.drawBitmap(pointBitmap,pointX-pointBitmap.width/2,pointY-pointBitmap.height,paint)
    }

    @Throws(IOException::class)
    private fun getFileFromAssets(fileName: String): File = File(cacheDir, fileName)
        .also {
            if (!it.exists()) {
                it.outputStream().use { cache ->
                    assets.open(fileName).use { inputStream ->
                        inputStream.copyTo(cache)
                    }
                }
            }
        }

    override fun onDestroy() {
        super.onDestroy()
        closeMap(handle!!)
    }

    /**
     * A native method that is implemented by the 'testradioavionica' native library,
     * which is packaged with this application.
     */
    private external fun openMapFile(filePath: String): Long
    private external fun renderViewport(mapHandle: Long, currentPoint: MapPoint, mapBitmap: Bitmap): Boolean
    private external fun getMapSize(mapHandle: Long): MapSize
    private external fun closeMap(mapHandle: Long)
    private external fun mapXYtoGeoWGS84(mapHandle: Long, point : MapPoint): MapGeoPoint
    private external fun mapGeoToXY(mapHandle: Long, point: MapGeoPoint): MapPoint

    companion object {
        // Used to load the 'testradioavionica' library on application startup.
        init {
            System.loadLibrary("testradioavionica")
        }
    }
}