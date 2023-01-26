package com.example.testmobint.api

import com.example.testmobint.api.response.Root
import retrofit2.Call
import retrofit2.http.Body
import retrofit2.http.Header
import retrofit2.http.Headers
import retrofit2.http.POST
import retrofit2.http.Query

interface CardAPI {

    @POST("getAllCompanies")
    @Headers("Content-Type: application/json")
    fun getAllCards(@Header("TOKEN") token: Int,@Body offset: OffsetBody): Call<List<Root>>

    @POST("getAllCompaniesIdeal")
    @Headers("Content-Type: application/json")
    fun getAllCardsIdeal(@Header("TOKEN") token: Int,@Body offset: OffsetBody): Call<List<Root>>

    @POST("getAllCompaniesLong")
    @Headers("Content-Type: application/json")
    fun getAllCardsLong(@Header("TOKEN") token: Int,@Body offset: OffsetBody): Call<List<Root>>

    @POST("getAllCompaniesError")
    @Headers("Content-Type: application/json")
    fun getAllCardsError(@Header("TOKEN") token: Int,@Body offset: OffsetBody): Call<List<Root>>
}