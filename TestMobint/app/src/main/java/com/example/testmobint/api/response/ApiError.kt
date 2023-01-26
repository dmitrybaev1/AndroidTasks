package com.example.testmobint.api.response

import com.fasterxml.jackson.annotation.JsonProperty
import okhttp3.ResponseBody
import retrofit2.Response

data class ApiError(
    @JsonProperty("type")
    val type: String,
    @JsonProperty("message")
    val message: String
)
