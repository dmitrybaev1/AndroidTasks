package com.example.testmobint.api

import com.example.testmobint.api.response.ApiError
import retrofit2.Response

object ErrorUtils {
    fun parseError(response: Response<*>): ApiError {
        val converter = CardRetrofitClient.instance.responseBodyConverter<ApiError>(
            ApiError::class.java,
            arrayOf<Annotation>())
        val apiError: ApiError
        try{
            apiError = response.errorBody()?.let { converter.convert(it) }!!
        }
        catch (e: Exception){
            return ApiError("","")
        }
        return apiError
    }
}