package com.example.testmobint

import android.os.Bundle
import android.view.LayoutInflater
import android.view.MotionEvent
import android.view.View
import android.view.ViewGroup
import androidx.appcompat.app.AlertDialog
import androidx.fragment.app.Fragment
import androidx.fragment.app.viewModels
import androidx.recyclerview.widget.LinearLayoutManager
import androidx.recyclerview.widget.RecyclerView
import com.example.testmobint.entities.CardPreloader

class CardFragment : Fragment() {
    private val cardViewModel: CardViewModel by viewModels()
    private lateinit var cardRecyclerView: RecyclerView
    private var cardAdapter: CardAdapter? = null
    private var isRequestInProgress = false
    override fun onCreateView(
        inflater: LayoutInflater,
        container: ViewGroup?,
        savedInstanceState: Bundle?
    ): View? {
        val view = inflater.inflate(R.layout.fragment_card,container,false)

        cardRecyclerView = view.findViewById(R.id.cardRecyclerView)
        cardRecyclerView.layoutManager = LinearLayoutManager(activity)

        cardViewModel.cardItemsLiveData.observe(viewLifecycleOwner) {list ->
            cardAdapter?.notifyDataSetChanged() ?: kotlin.run {
                cardAdapter = CardAdapter(list)
                cardRecyclerView.adapter = cardAdapter
            }
            isRequestInProgress = false
        }
        cardViewModel.errorMessageLiveData.observe(viewLifecycleOwner) {message ->
            val alertDialog: AlertDialog? = activity?.let {
                val builder = AlertDialog.Builder(it)
                builder.apply {
                    setTitle(R.string.error)
                    setMessage(message)
                    setPositiveButton(R.string.ok) { dialog, _ ->
                        dialog.dismiss()
                    }
                }
                builder.create()
            }
            alertDialog?.show()
            isRequestInProgress = false
        }
        cardRecyclerView.addOnScrollListener(object: RecyclerView.OnScrollListener(){
            override fun onScrollStateChanged(recyclerView: RecyclerView, newState: Int) {
                super.onScrollStateChanged(recyclerView, newState)
                val position = (recyclerView.layoutManager as LinearLayoutManager).findLastVisibleItemPosition()
                val list = (recyclerView.adapter as CardAdapter).list
                if(list[position] is CardPreloader && !isRequestInProgress) {
                    isRequestInProgress = true
                    cardViewModel.getCards()
                }
            }
        })
        return view
    }

    override fun onStart() {
        super.onStart()
        cardViewModel.initCardAdapter()
        cardViewModel.getCards()
    }
}