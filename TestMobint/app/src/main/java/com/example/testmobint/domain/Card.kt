package com.example.testmobint.domain

data class Card (
    val companyId: String,
    val companyName: String,
    val logoUrl: String,
    val mark: Int,
    val cashToMark: Int,
    val loyaltyName: String,
    val cardColors: CardColors
)