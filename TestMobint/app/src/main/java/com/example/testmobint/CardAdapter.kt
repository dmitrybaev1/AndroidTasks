package com.example.testmobint

import android.content.Context
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import androidx.appcompat.app.AlertDialog
import androidx.databinding.DataBindingUtil
import androidx.recyclerview.widget.RecyclerView
import androidx.recyclerview.widget.RecyclerView.ViewHolder
import com.example.testmobint.databinding.CardItemBinding
import com.example.testmobint.entities.CardAdapterItem
import com.example.testmobint.entities.CardItem
import com.example.testmobint.entities.CardPreloader

class CardAdapter(val list: List<CardAdapterItem>) : RecyclerView.Adapter<ViewHolder>() {

    companion object{
        const val ITEM_TYPE_CARD = 0
        const val ITEM_TYPE_PRELOADER = 1
    }
    inner class CardViewHolder(val binding: CardItemBinding) : ViewHolder(binding.root){
        fun bind(cardItem: CardItem){
            binding.setVariable(BR.cardItem,cardItem)
            binding.executePendingBindings()
        }
    }

    inner class PreloaderViewHolder(v: View) : ViewHolder(v)

    override fun onCreateViewHolder(parent: ViewGroup, viewType: Int): ViewHolder {
        return when(viewType){
            ITEM_TYPE_CARD -> {
                val binding = DataBindingUtil.inflate<CardItemBinding>(LayoutInflater.from(parent.context), R.layout.card_item, parent, false);
                CardViewHolder(binding)
            }
            ITEM_TYPE_PRELOADER -> {
                val view = LayoutInflater.from(parent.context).inflate(R.layout.card_preloader,parent,false)
                PreloaderViewHolder(view)
            }
            else -> throw  ClassCastException("Unknown viewType $viewType")
        }
    }

    override fun onBindViewHolder(holder: ViewHolder, position: Int) {
        holder.apply {
            if(this is CardViewHolder){
                val cardItem = list[position] as CardItem
                bind(cardItem)
                binding.apply {
                    eyeImageButton.setOnClickListener {
                        val alertDialog = makeOnClickAlertDialog(it.context,ButtonType.EYE,cardItem.companyId)
                        alertDialog.show()
                    }
                    trashImageButton.setOnClickListener {
                        val alertDialog = makeOnClickAlertDialog(it.context,ButtonType.TRASH,cardItem.companyId)
                        alertDialog.show()
                    }
                    detailsButton.setOnClickListener {
                        val alertDialog = makeOnClickAlertDialog(it.context,ButtonType.DETAILS,cardItem.companyId)
                        alertDialog.show()
                    }
                }
            }
        }
    }

    override fun getItemCount(): Int = list.size

    override fun getItemViewType(position: Int): Int {
        return when(list[position]){
            is CardItem -> ITEM_TYPE_CARD
            is CardPreloader -> ITEM_TYPE_PRELOADER
        }
    }

    private fun makeOnClickAlertDialog(context: Context,buttonType: ButtonType,companyId: String): AlertDialog{
        val builder = AlertDialog.Builder(context)
        builder.apply {
            setTitle(R.string.attention)
            when(buttonType){
                ButtonType.EYE -> setMessage("Нажата кнопка просмотра\nид компании:${companyId}")
                ButtonType.TRASH -> setMessage("Нажата кнопка удаления\nид компании:${companyId}")
                ButtonType.DETAILS -> setMessage("Нажата кнопка подробнее\nид компании:${companyId}")
            }
            setPositiveButton(R.string.ok) { dialog, _ ->
                dialog.dismiss()
            }
        }
        return builder.create()
    }
    enum class ButtonType{EYE,TRASH,DETAILS}
}