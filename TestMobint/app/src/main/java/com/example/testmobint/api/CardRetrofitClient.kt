package com.example.testmobint.api

import retrofit2.converter.jackson.JacksonConverterFactory

object CardRetrofitClient {
    val instance = retrofit2.Retrofit.Builder()
        .baseUrl("http://dev.bonusmoney.pro/mobileapp/")
        .addConverterFactory(JacksonConverterFactory.create())
        .build()
    val cardApi = instance.create(CardAPI::class.java)
}