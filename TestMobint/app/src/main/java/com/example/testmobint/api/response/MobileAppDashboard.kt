package com.example.testmobint.api.response

import com.fasterxml.jackson.annotation.JsonProperty

data class MobileAppDashboard (
    @JsonProperty("companyName")
    val companyName: String,
    @JsonProperty("logo")
    val logo: String,
    @JsonProperty("backgroundColor")
    val backgroundColor: String,
    @JsonProperty("mainColor")
    val mainColor: String,
    @JsonProperty("cardBackgroundColor")
    val cardBackgroundColor: String,
    @JsonProperty("textColor")
    val textColor: String,
    @JsonProperty("highlightTextColor")
    val highlightTextColor: String,
    @JsonProperty("accentColor")
    val accentColor: String
    )