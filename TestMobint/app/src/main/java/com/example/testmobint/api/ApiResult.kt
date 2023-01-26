package com.example.testmobint.api

sealed interface ApiResult<out R>{

    class Success<out T>(val data: T): ApiResult<T>

    class Failure(val message: String): ApiResult<Nothing>

    object NetworkFailure : ApiResult<Nothing>
}