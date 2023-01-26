package com.example.testmobint.entities

import com.example.testmobint.domain.CardColors

sealed interface CardAdapterItem

data class CardItem (
    val companyId: String,
    val companyName: String,
    val logoUrl: String,
    val mark: Int,
    val cashToMark: Int,
    val loyaltyName: String,
    val cardColors: CardColors
) : CardAdapterItem

object CardPreloader : CardAdapterItem