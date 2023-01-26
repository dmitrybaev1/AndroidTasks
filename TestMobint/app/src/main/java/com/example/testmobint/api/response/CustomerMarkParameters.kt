package com.example.testmobint.api.response

import com.fasterxml.jackson.annotation.JsonProperty

data class CustomerMarkParameters(
    @JsonProperty("loyaltyLevel")
    val loyaltyLevel: LoyaltyLevel,
    @JsonProperty("mark")
    val mark: Int
)
