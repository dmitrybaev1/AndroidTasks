package com.example.testmobint.api.response

import com.fasterxml.jackson.annotation.JsonProperty

data class Root(
    @JsonProperty("company")
    val company: Company,
    @JsonProperty("customerMarkParameters")
    val customerMarkParameters: CustomerMarkParameters,
    @JsonProperty("mobileAppDashboard")
    val mobileAppDashboard: MobileAppDashboard
)
