package com.example.testmobint.api.response

import com.fasterxml.jackson.annotation.JsonProperty

data class Company(
    @JsonProperty("companyId")
    val companyId: String
)
