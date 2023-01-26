package com.example.testmobint

import android.content.res.ColorStateList
import android.graphics.*
import android.graphics.drawable.BitmapDrawable
import android.graphics.drawable.Drawable
import android.view.View
import android.widget.Button
import android.widget.ImageView
import android.widget.TextView
import androidx.core.content.ContextCompat
import androidx.core.content.res.ResourcesCompat
import androidx.core.graphics.drawable.toBitmap
import androidx.core.graphics.drawable.toDrawable
import androidx.databinding.BindingAdapter
import androidx.databinding.BindingConversion
import com.bumptech.glide.Glide

@BindingAdapter("android:background")
fun setBackground(view: View, color: String){
    view.setBackgroundColor(Color.parseColor(color))
}

@BindingAdapter("app:url")
fun loadImage(view: ImageView, url: String){
    Glide.with(view.context).load(url).into(view)
}

@BindingAdapter("app:imageColor")
fun changeImageButtonColor(view: ImageView, color: String){
    val bitmap = (view.drawable as BitmapDrawable).bitmap.copy(Bitmap.Config.ARGB_8888, true)
    val paint = Paint()
    val filter = PorterDuffColorFilter(Color.parseColor(color),PorterDuff.Mode.SRC_IN)
    paint.colorFilter = filter
    val canvas = Canvas(bitmap)
    canvas.drawBitmap(bitmap,0f,0f,paint)
    view.setImageBitmap(bitmap)
}

@BindingAdapter("android:backgroundTint")
fun setBackgroundTint(view: View, color: String){
    view.backgroundTintList = ColorStateList.valueOf(Color.parseColor(color))
}

@BindingAdapter("android:textColor")
fun setTextColor(view: TextView, color: String){
    view.setTextColor(Color.parseColor(color))
}

@BindingAdapter("android:text")
fun setText(view: TextView, value: Int){
    view.text = value.toString()
}