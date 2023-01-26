package com.example.testmobint

import com.example.testmobint.api.ApiResult
import com.example.testmobint.api.CardRetrofitClient
import com.example.testmobint.api.ErrorUtils
import com.example.testmobint.api.OffsetBody
import com.example.testmobint.api.response.Root
import com.example.testmobint.domain.Card
import com.example.testmobint.domain.CardColors
import kotlinx.coroutines.Dispatchers
import kotlinx.coroutines.withContext

class CardRepository {
    suspend fun getCards(token: Int,offset: Int): ApiResult<List<Card>> =
        withContext(Dispatchers.IO){
            try {
                val response = CardRetrofitClient.cardApi.getAllCards(token, OffsetBody(offset)).execute()
                if (response.isSuccessful){
                    val list = response.body()!!
                    ApiResult.Success(mapCardResponseToCards(list))
                }
                else {
                    when(response.code()){
                        401 -> ApiResult.Failure("Ошибка авторизации")
                        400 -> {
                            val apiError = ErrorUtils.parseError(response)
                            ApiResult.Failure(apiError.message)
                        }
                        else -> ApiResult.Failure("Все упало(")
                    }
                }
            }
            catch(e: Exception){
                e.printStackTrace()
                ApiResult.NetworkFailure
            }
        }

    private fun mapCardResponseToCards(list: List<Root>): List<Card>{
        val cardList = arrayListOf<Card>()
        for(root in list){
            val cardColors = CardColors(
                cardBackgroundColor = root.mobileAppDashboard.cardBackgroundColor,
                backgroundColor = root.mobileAppDashboard.backgroundColor,
                mainColor = root.mobileAppDashboard.mainColor,
                textColor = root.mobileAppDashboard.textColor,
                highlightTextColor = root.mobileAppDashboard.highlightTextColor,
                accentColor = root.mobileAppDashboard.accentColor
            )
            val card = Card(
                companyId = root.company.companyId,
                companyName = root.mobileAppDashboard.companyName,
                logoUrl = root.mobileAppDashboard.logo,
                mark = root.customerMarkParameters.mark,
                cashToMark = root.customerMarkParameters.loyaltyLevel.cashToMark,
                loyaltyName = root.customerMarkParameters.loyaltyLevel.name,
                cardColors = cardColors
            )
            cardList.add(card)
        }
        return cardList
    }
}