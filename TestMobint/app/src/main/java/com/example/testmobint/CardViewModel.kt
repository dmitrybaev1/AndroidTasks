package com.example.testmobint

import androidx.lifecycle.LiveData
import androidx.lifecycle.MutableLiveData
import androidx.lifecycle.ViewModel
import androidx.lifecycle.viewModelScope
import com.example.testmobint.api.ApiResult
import com.example.testmobint.domain.Card
import com.example.testmobint.entities.CardAdapterItem
import com.example.testmobint.entities.CardItem
import com.example.testmobint.entities.CardPreloader
import kotlinx.coroutines.launch

class CardViewModel : ViewModel() {

    private val token = 123
    private var offset = 0

    private val _cardItemsLiveData: MutableLiveData<List<CardAdapterItem>> = MutableLiveData<List<CardAdapterItem>>()
    val cardItemsLiveData: LiveData<List<CardAdapterItem>> = _cardItemsLiveData

    private var cardAdapterItemList: ArrayList<CardAdapterItem> = arrayListOf(CardPreloader)

    private val _errorMessageLiveData: MutableLiveData<String> = MutableLiveData<String>()
    val errorMessageLiveData: LiveData<String> = _errorMessageLiveData

    private val cardRepository = CardRepository()

    var isEndOfList = false

    fun initCardAdapter(){
        _cardItemsLiveData.value = cardAdapterItemList
    }

    fun getCards(){
        viewModelScope.launch {
            when(val result = cardRepository.getCards(token, offset)){
                is ApiResult.Success<List<Card>> -> {
                    val list = result.data
                    if(cardAdapterItemList.last() is CardPreloader)
                        cardAdapterItemList.removeLast()
                    if(list.isNotEmpty()) {
                        cardAdapterItemList.addAll(mapCardsToCardItems(list))
                        cardAdapterItemList.add(CardPreloader)
                        offset += result.data.size
                    }
                    else
                        isEndOfList = true
                    _cardItemsLiveData.value = cardAdapterItemList
                }
                is ApiResult.Failure -> _errorMessageLiveData.value = result.message
                is ApiResult.NetworkFailure -> _errorMessageLiveData.value = "Ошибка сети"
            }
        }
    }
    private fun mapCardsToCardItems(list: List<Card>): List<CardAdapterItem>{
        val cardItemList = arrayListOf<CardAdapterItem>()
        for(card in list){
            val cardItem = CardItem(
                companyId = card.companyId,
                companyName = card.companyName,
                logoUrl = card.logoUrl,
                mark = card.mark,
                cashToMark = card.cashToMark,
                loyaltyName = card.loyaltyName,
                cardColors = card.cardColors
            )
            cardItemList.add(cardItem)
        }
        return cardItemList
    }
}