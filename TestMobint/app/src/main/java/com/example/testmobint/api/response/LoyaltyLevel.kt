package com.example.testmobint.api.response

import com.fasterxml.jackson.annotation.JsonProperty

data class LoyaltyLevel(
    @JsonProperty("number")
    val number: Int,
    @JsonProperty("name")
    val name: String,
    @JsonProperty("requiredSum")
    val requiredSum: Int,
    @JsonProperty("markToCash")
    val markToCash: Int,
    @JsonProperty("cashToMark")
    val cashToMark: Int
)
