package com.example.testradioavionica

import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import android.widget.ImageView
import android.widget.TextView
import androidx.recyclerview.widget.RecyclerView
import androidx.recyclerview.widget.RecyclerView.ViewHolder
import com.example.testradioavionica.entities.MapGeoPoint

class PointAdapter(private val list: List<MapGeoPoint>) : RecyclerView.Adapter<PointAdapter.PointViewHolder>() {
    inner class PointViewHolder(v: View) : ViewHolder(v){
        val coordinatesTextView: TextView = v.findViewById(R.id.coordinatesTextView)
    }

    override fun onCreateViewHolder(parent: ViewGroup, viewType: Int): PointViewHolder {
        val view = LayoutInflater.from(parent.context).inflate(R.layout.geo_point_item,parent,false)
        return PointViewHolder(view)
    }

    override fun onBindViewHolder(holder: PointViewHolder, position: Int) {
        holder.coordinatesTextView.text = "x: ${list[position].b}, y: ${list[position].l}"
    }

    override fun getItemCount(): Int = list.size
}