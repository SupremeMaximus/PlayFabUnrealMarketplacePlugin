//////////////////////////////////////////////////////
// Copyright (C) Microsoft. 2018. All rights reserved.
//////////////////////////////////////////////////////


// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#include "Core/PlayFabCloudScriptAPI.h"
#include "Core/PlayFabSettings.h"
#include "Core/PlayFabResultHandler.h"
#include "PlayFab.h"

using namespace PlayFab;
using namespace PlayFab::CloudScriptModels;

UPlayFabCloudScriptAPI::UPlayFabCloudScriptAPI() {}

UPlayFabCloudScriptAPI::~UPlayFabCloudScriptAPI() {}

int UPlayFabCloudScriptAPI::GetPendingCalls() const
{
    return PlayFabRequestHandler::GetPendingCalls();
}

FString UPlayFabCloudScriptAPI::GetBuildIdentifier() const
{
    return PlayFabSettings::buildIdentifier;
}


bool UPlayFabCloudScriptAPI::ExecuteEntityCloudScript(
    CloudScriptModels::FExecuteEntityCloudScriptRequest& request,
    const FExecuteEntityCloudScriptDelegate& SuccessDelegate,
    const FPlayFabErrorDelegate& ErrorDelegate)
{
    FString entityToken = request.AuthenticationContext.IsValid() ? request.AuthenticationContext->GetEntityToken() : PlayFabSettings::GetEntityToken();
    if (entityToken.Len() == 0) {
        UE_LOG(LogPlayFabCpp, Error, TEXT("You must call GetEntityToken API Method before calling this function."));
    }


    auto HttpRequest = PlayFabRequestHandler::SendRequest(nullptr, TEXT("/CloudScript/ExecuteEntityCloudScript"), request.toJSONString(), TEXT("X-EntityToken"), entityToken);
    HttpRequest->OnProcessRequestComplete().BindRaw(this, &UPlayFabCloudScriptAPI::OnExecuteEntityCloudScriptResult, SuccessDelegate, ErrorDelegate);
    return HttpRequest->ProcessRequest();
}

void UPlayFabCloudScriptAPI::OnExecuteEntityCloudScriptResult(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FExecuteEntityCloudScriptDelegate SuccessDelegate, FPlayFabErrorDelegate ErrorDelegate)
{
    CloudScriptModels::FExecuteCloudScriptResult outResult;
    FPlayFabCppError errorResult;
    if (PlayFabRequestHandler::DecodeRequest(HttpRequest, HttpResponse, bSucceeded, outResult, errorResult))
    {
        SuccessDelegate.ExecuteIfBound(outResult);
    }
    else
    {
        ErrorDelegate.ExecuteIfBound(errorResult);
    }
}

bool UPlayFabCloudScriptAPI::ExecuteFunction(
    CloudScriptModels::FExecuteFunctionRequest& request,
    const FExecuteFunctionDelegate& SuccessDelegate,
    const FPlayFabErrorDelegate& ErrorDelegate)
{
    FString entityToken = request.AuthenticationContext.IsValid() ? request.AuthenticationContext->GetEntityToken() : PlayFabSettings::GetEntityToken();
    if (entityToken.Len() == 0) {
        UE_LOG(LogPlayFabCpp, Error, TEXT("You must call GetEntityToken API Method before calling this function."));
    }

    FString localApiServer = PlayFabSettings::GetLocalApiServer();
    if (!localApiServer.IsEmpty())
    {
        FString endpoint = TEXT("/CloudScript/ExecuteFunction");
        endpoint.RemoveFromStart(TEXT("/"));
        auto HttpRequest = PlayFabRequestHandler::SendFullUrlRequest(localApiServer + endpoint, request.toJSONString(), TEXT("X-EntityToken"), entityToken);
        HttpRequest->OnProcessRequestComplete().BindRaw(this, &UPlayFabCloudScriptAPI::OnExecuteFunctionResult, SuccessDelegate, ErrorDelegate);
        return HttpRequest->ProcessRequest();
    }

    auto HttpRequest = PlayFabRequestHandler::SendRequest(nullptr, TEXT("/CloudScript/ExecuteFunction"), request.toJSONString(), TEXT("X-EntityToken"), entityToken);
    HttpRequest->OnProcessRequestComplete().BindRaw(this, &UPlayFabCloudScriptAPI::OnExecuteFunctionResult, SuccessDelegate, ErrorDelegate);
    return HttpRequest->ProcessRequest();
}

void UPlayFabCloudScriptAPI::OnExecuteFunctionResult(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FExecuteFunctionDelegate SuccessDelegate, FPlayFabErrorDelegate ErrorDelegate)
{
    CloudScriptModels::FExecuteFunctionResult outResult;
    FPlayFabCppError errorResult;
    if (PlayFabRequestHandler::DecodeRequest(HttpRequest, HttpResponse, bSucceeded, outResult, errorResult))
    {
        SuccessDelegate.ExecuteIfBound(outResult);
    }
    else
    {
        ErrorDelegate.ExecuteIfBound(errorResult);
    }
}

bool UPlayFabCloudScriptAPI::GetFunction(
    CloudScriptModels::FGetFunctionRequest& request,
    const FGetFunctionDelegate& SuccessDelegate,
    const FPlayFabErrorDelegate& ErrorDelegate)
{
    FString entityToken = request.AuthenticationContext.IsValid() ? request.AuthenticationContext->GetEntityToken() : PlayFabSettings::GetEntityToken();
    if (entityToken.Len() == 0) {
        UE_LOG(LogPlayFabCpp, Error, TEXT("You must call GetEntityToken API Method before calling this function."));
    }


    auto HttpRequest = PlayFabRequestHandler::SendRequest(nullptr, TEXT("/CloudScript/GetFunction"), request.toJSONString(), TEXT("X-EntityToken"), entityToken);
    HttpRequest->OnProcessRequestComplete().BindRaw(this, &UPlayFabCloudScriptAPI::OnGetFunctionResult, SuccessDelegate, ErrorDelegate);
    return HttpRequest->ProcessRequest();
}

void UPlayFabCloudScriptAPI::OnGetFunctionResult(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FGetFunctionDelegate SuccessDelegate, FPlayFabErrorDelegate ErrorDelegate)
{
    CloudScriptModels::FGetFunctionResult outResult;
    FPlayFabCppError errorResult;
    if (PlayFabRequestHandler::DecodeRequest(HttpRequest, HttpResponse, bSucceeded, outResult, errorResult))
    {
        SuccessDelegate.ExecuteIfBound(outResult);
    }
    else
    {
        ErrorDelegate.ExecuteIfBound(errorResult);
    }
}

bool UPlayFabCloudScriptAPI::ListFunctions(
    CloudScriptModels::FListFunctionsRequest& request,
    const FListFunctionsDelegate& SuccessDelegate,
    const FPlayFabErrorDelegate& ErrorDelegate)
{
    FString entityToken = request.AuthenticationContext.IsValid() ? request.AuthenticationContext->GetEntityToken() : PlayFabSettings::GetEntityToken();
    if (entityToken.Len() == 0) {
        UE_LOG(LogPlayFabCpp, Error, TEXT("You must call GetEntityToken API Method before calling this function."));
    }


    auto HttpRequest = PlayFabRequestHandler::SendRequest(nullptr, TEXT("/CloudScript/ListFunctions"), request.toJSONString(), TEXT("X-EntityToken"), entityToken);
    HttpRequest->OnProcessRequestComplete().BindRaw(this, &UPlayFabCloudScriptAPI::OnListFunctionsResult, SuccessDelegate, ErrorDelegate);
    return HttpRequest->ProcessRequest();
}

void UPlayFabCloudScriptAPI::OnListFunctionsResult(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FListFunctionsDelegate SuccessDelegate, FPlayFabErrorDelegate ErrorDelegate)
{
    CloudScriptModels::FListFunctionsResult outResult;
    FPlayFabCppError errorResult;
    if (PlayFabRequestHandler::DecodeRequest(HttpRequest, HttpResponse, bSucceeded, outResult, errorResult))
    {
        SuccessDelegate.ExecuteIfBound(outResult);
    }
    else
    {
        ErrorDelegate.ExecuteIfBound(errorResult);
    }
}

bool UPlayFabCloudScriptAPI::ListHttpFunctions(
    CloudScriptModels::FListFunctionsRequest& request,
    const FListHttpFunctionsDelegate& SuccessDelegate,
    const FPlayFabErrorDelegate& ErrorDelegate)
{
    FString entityToken = request.AuthenticationContext.IsValid() ? request.AuthenticationContext->GetEntityToken() : PlayFabSettings::GetEntityToken();
    if (entityToken.Len() == 0) {
        UE_LOG(LogPlayFabCpp, Error, TEXT("You must call GetEntityToken API Method before calling this function."));
    }


    auto HttpRequest = PlayFabRequestHandler::SendRequest(nullptr, TEXT("/CloudScript/ListHttpFunctions"), request.toJSONString(), TEXT("X-EntityToken"), entityToken);
    HttpRequest->OnProcessRequestComplete().BindRaw(this, &UPlayFabCloudScriptAPI::OnListHttpFunctionsResult, SuccessDelegate, ErrorDelegate);
    return HttpRequest->ProcessRequest();
}

void UPlayFabCloudScriptAPI::OnListHttpFunctionsResult(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FListHttpFunctionsDelegate SuccessDelegate, FPlayFabErrorDelegate ErrorDelegate)
{
    CloudScriptModels::FListHttpFunctionsResult outResult;
    FPlayFabCppError errorResult;
    if (PlayFabRequestHandler::DecodeRequest(HttpRequest, HttpResponse, bSucceeded, outResult, errorResult))
    {
        SuccessDelegate.ExecuteIfBound(outResult);
    }
    else
    {
        ErrorDelegate.ExecuteIfBound(errorResult);
    }
}

bool UPlayFabCloudScriptAPI::ListQueuedFunctions(
    CloudScriptModels::FListFunctionsRequest& request,
    const FListQueuedFunctionsDelegate& SuccessDelegate,
    const FPlayFabErrorDelegate& ErrorDelegate)
{
    FString entityToken = request.AuthenticationContext.IsValid() ? request.AuthenticationContext->GetEntityToken() : PlayFabSettings::GetEntityToken();
    if (entityToken.Len() == 0) {
        UE_LOG(LogPlayFabCpp, Error, TEXT("You must call GetEntityToken API Method before calling this function."));
    }


    auto HttpRequest = PlayFabRequestHandler::SendRequest(nullptr, TEXT("/CloudScript/ListQueuedFunctions"), request.toJSONString(), TEXT("X-EntityToken"), entityToken);
    HttpRequest->OnProcessRequestComplete().BindRaw(this, &UPlayFabCloudScriptAPI::OnListQueuedFunctionsResult, SuccessDelegate, ErrorDelegate);
    return HttpRequest->ProcessRequest();
}

void UPlayFabCloudScriptAPI::OnListQueuedFunctionsResult(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FListQueuedFunctionsDelegate SuccessDelegate, FPlayFabErrorDelegate ErrorDelegate)
{
    CloudScriptModels::FListQueuedFunctionsResult outResult;
    FPlayFabCppError errorResult;
    if (PlayFabRequestHandler::DecodeRequest(HttpRequest, HttpResponse, bSucceeded, outResult, errorResult))
    {
        SuccessDelegate.ExecuteIfBound(outResult);
    }
    else
    {
        ErrorDelegate.ExecuteIfBound(errorResult);
    }
}

bool UPlayFabCloudScriptAPI::PostFunctionResultForEntityTriggeredAction(
    CloudScriptModels::FPostFunctionResultForEntityTriggeredActionRequest& request,
    const FPostFunctionResultForEntityTriggeredActionDelegate& SuccessDelegate,
    const FPlayFabErrorDelegate& ErrorDelegate)
{
    FString entityToken = request.AuthenticationContext.IsValid() ? request.AuthenticationContext->GetEntityToken() : PlayFabSettings::GetEntityToken();
    if (entityToken.Len() == 0) {
        UE_LOG(LogPlayFabCpp, Error, TEXT("You must call GetEntityToken API Method before calling this function."));
    }


    auto HttpRequest = PlayFabRequestHandler::SendRequest(nullptr, TEXT("/CloudScript/PostFunctionResultForEntityTriggeredAction"), request.toJSONString(), TEXT("X-EntityToken"), entityToken);
    HttpRequest->OnProcessRequestComplete().BindRaw(this, &UPlayFabCloudScriptAPI::OnPostFunctionResultForEntityTriggeredActionResult, SuccessDelegate, ErrorDelegate);
    return HttpRequest->ProcessRequest();
}

void UPlayFabCloudScriptAPI::OnPostFunctionResultForEntityTriggeredActionResult(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FPostFunctionResultForEntityTriggeredActionDelegate SuccessDelegate, FPlayFabErrorDelegate ErrorDelegate)
{
    CloudScriptModels::FEmptyResult outResult;
    FPlayFabCppError errorResult;
    if (PlayFabRequestHandler::DecodeRequest(HttpRequest, HttpResponse, bSucceeded, outResult, errorResult))
    {
        SuccessDelegate.ExecuteIfBound(outResult);
    }
    else
    {
        ErrorDelegate.ExecuteIfBound(errorResult);
    }
}

bool UPlayFabCloudScriptAPI::PostFunctionResultForFunctionExecution(
    CloudScriptModels::FPostFunctionResultForFunctionExecutionRequest& request,
    const FPostFunctionResultForFunctionExecutionDelegate& SuccessDelegate,
    const FPlayFabErrorDelegate& ErrorDelegate)
{
    FString entityToken = request.AuthenticationContext.IsValid() ? request.AuthenticationContext->GetEntityToken() : PlayFabSettings::GetEntityToken();
    if (entityToken.Len() == 0) {
        UE_LOG(LogPlayFabCpp, Error, TEXT("You must call GetEntityToken API Method before calling this function."));
    }


    auto HttpRequest = PlayFabRequestHandler::SendRequest(nullptr, TEXT("/CloudScript/PostFunctionResultForFunctionExecution"), request.toJSONString(), TEXT("X-EntityToken"), entityToken);
    HttpRequest->OnProcessRequestComplete().BindRaw(this, &UPlayFabCloudScriptAPI::OnPostFunctionResultForFunctionExecutionResult, SuccessDelegate, ErrorDelegate);
    return HttpRequest->ProcessRequest();
}

void UPlayFabCloudScriptAPI::OnPostFunctionResultForFunctionExecutionResult(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FPostFunctionResultForFunctionExecutionDelegate SuccessDelegate, FPlayFabErrorDelegate ErrorDelegate)
{
    CloudScriptModels::FEmptyResult outResult;
    FPlayFabCppError errorResult;
    if (PlayFabRequestHandler::DecodeRequest(HttpRequest, HttpResponse, bSucceeded, outResult, errorResult))
    {
        SuccessDelegate.ExecuteIfBound(outResult);
    }
    else
    {
        ErrorDelegate.ExecuteIfBound(errorResult);
    }
}

bool UPlayFabCloudScriptAPI::PostFunctionResultForPlayerTriggeredAction(
    CloudScriptModels::FPostFunctionResultForPlayerTriggeredActionRequest& request,
    const FPostFunctionResultForPlayerTriggeredActionDelegate& SuccessDelegate,
    const FPlayFabErrorDelegate& ErrorDelegate)
{
    FString entityToken = request.AuthenticationContext.IsValid() ? request.AuthenticationContext->GetEntityToken() : PlayFabSettings::GetEntityToken();
    if (entityToken.Len() == 0) {
        UE_LOG(LogPlayFabCpp, Error, TEXT("You must call GetEntityToken API Method before calling this function."));
    }


    auto HttpRequest = PlayFabRequestHandler::SendRequest(nullptr, TEXT("/CloudScript/PostFunctionResultForPlayerTriggeredAction"), request.toJSONString(), TEXT("X-EntityToken"), entityToken);
    HttpRequest->OnProcessRequestComplete().BindRaw(this, &UPlayFabCloudScriptAPI::OnPostFunctionResultForPlayerTriggeredActionResult, SuccessDelegate, ErrorDelegate);
    return HttpRequest->ProcessRequest();
}

void UPlayFabCloudScriptAPI::OnPostFunctionResultForPlayerTriggeredActionResult(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FPostFunctionResultForPlayerTriggeredActionDelegate SuccessDelegate, FPlayFabErrorDelegate ErrorDelegate)
{
    CloudScriptModels::FEmptyResult outResult;
    FPlayFabCppError errorResult;
    if (PlayFabRequestHandler::DecodeRequest(HttpRequest, HttpResponse, bSucceeded, outResult, errorResult))
    {
        SuccessDelegate.ExecuteIfBound(outResult);
    }
    else
    {
        ErrorDelegate.ExecuteIfBound(errorResult);
    }
}

bool UPlayFabCloudScriptAPI::PostFunctionResultForScheduledTask(
    CloudScriptModels::FPostFunctionResultForScheduledTaskRequest& request,
    const FPostFunctionResultForScheduledTaskDelegate& SuccessDelegate,
    const FPlayFabErrorDelegate& ErrorDelegate)
{
    FString entityToken = request.AuthenticationContext.IsValid() ? request.AuthenticationContext->GetEntityToken() : PlayFabSettings::GetEntityToken();
    if (entityToken.Len() == 0) {
        UE_LOG(LogPlayFabCpp, Error, TEXT("You must call GetEntityToken API Method before calling this function."));
    }


    auto HttpRequest = PlayFabRequestHandler::SendRequest(nullptr, TEXT("/CloudScript/PostFunctionResultForScheduledTask"), request.toJSONString(), TEXT("X-EntityToken"), entityToken);
    HttpRequest->OnProcessRequestComplete().BindRaw(this, &UPlayFabCloudScriptAPI::OnPostFunctionResultForScheduledTaskResult, SuccessDelegate, ErrorDelegate);
    return HttpRequest->ProcessRequest();
}

void UPlayFabCloudScriptAPI::OnPostFunctionResultForScheduledTaskResult(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FPostFunctionResultForScheduledTaskDelegate SuccessDelegate, FPlayFabErrorDelegate ErrorDelegate)
{
    CloudScriptModels::FEmptyResult outResult;
    FPlayFabCppError errorResult;
    if (PlayFabRequestHandler::DecodeRequest(HttpRequest, HttpResponse, bSucceeded, outResult, errorResult))
    {
        SuccessDelegate.ExecuteIfBound(outResult);
    }
    else
    {
        ErrorDelegate.ExecuteIfBound(errorResult);
    }
}

bool UPlayFabCloudScriptAPI::RegisterHttpFunction(
    CloudScriptModels::FRegisterHttpFunctionRequest& request,
    const FRegisterHttpFunctionDelegate& SuccessDelegate,
    const FPlayFabErrorDelegate& ErrorDelegate)
{
    FString entityToken = request.AuthenticationContext.IsValid() ? request.AuthenticationContext->GetEntityToken() : PlayFabSettings::GetEntityToken();
    if (entityToken.Len() == 0) {
        UE_LOG(LogPlayFabCpp, Error, TEXT("You must call GetEntityToken API Method before calling this function."));
    }


    auto HttpRequest = PlayFabRequestHandler::SendRequest(nullptr, TEXT("/CloudScript/RegisterHttpFunction"), request.toJSONString(), TEXT("X-EntityToken"), entityToken);
    HttpRequest->OnProcessRequestComplete().BindRaw(this, &UPlayFabCloudScriptAPI::OnRegisterHttpFunctionResult, SuccessDelegate, ErrorDelegate);
    return HttpRequest->ProcessRequest();
}

void UPlayFabCloudScriptAPI::OnRegisterHttpFunctionResult(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FRegisterHttpFunctionDelegate SuccessDelegate, FPlayFabErrorDelegate ErrorDelegate)
{
    CloudScriptModels::FEmptyResult outResult;
    FPlayFabCppError errorResult;
    if (PlayFabRequestHandler::DecodeRequest(HttpRequest, HttpResponse, bSucceeded, outResult, errorResult))
    {
        SuccessDelegate.ExecuteIfBound(outResult);
    }
    else
    {
        ErrorDelegate.ExecuteIfBound(errorResult);
    }
}

bool UPlayFabCloudScriptAPI::RegisterQueuedFunction(
    CloudScriptModels::FRegisterQueuedFunctionRequest& request,
    const FRegisterQueuedFunctionDelegate& SuccessDelegate,
    const FPlayFabErrorDelegate& ErrorDelegate)
{
    FString entityToken = request.AuthenticationContext.IsValid() ? request.AuthenticationContext->GetEntityToken() : PlayFabSettings::GetEntityToken();
    if (entityToken.Len() == 0) {
        UE_LOG(LogPlayFabCpp, Error, TEXT("You must call GetEntityToken API Method before calling this function."));
    }


    auto HttpRequest = PlayFabRequestHandler::SendRequest(nullptr, TEXT("/CloudScript/RegisterQueuedFunction"), request.toJSONString(), TEXT("X-EntityToken"), entityToken);
    HttpRequest->OnProcessRequestComplete().BindRaw(this, &UPlayFabCloudScriptAPI::OnRegisterQueuedFunctionResult, SuccessDelegate, ErrorDelegate);
    return HttpRequest->ProcessRequest();
}

void UPlayFabCloudScriptAPI::OnRegisterQueuedFunctionResult(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FRegisterQueuedFunctionDelegate SuccessDelegate, FPlayFabErrorDelegate ErrorDelegate)
{
    CloudScriptModels::FEmptyResult outResult;
    FPlayFabCppError errorResult;
    if (PlayFabRequestHandler::DecodeRequest(HttpRequest, HttpResponse, bSucceeded, outResult, errorResult))
    {
        SuccessDelegate.ExecuteIfBound(outResult);
    }
    else
    {
        ErrorDelegate.ExecuteIfBound(errorResult);
    }
}

bool UPlayFabCloudScriptAPI::UnregisterFunction(
    CloudScriptModels::FUnregisterFunctionRequest& request,
    const FUnregisterFunctionDelegate& SuccessDelegate,
    const FPlayFabErrorDelegate& ErrorDelegate)
{
    FString entityToken = request.AuthenticationContext.IsValid() ? request.AuthenticationContext->GetEntityToken() : PlayFabSettings::GetEntityToken();
    if (entityToken.Len() == 0) {
        UE_LOG(LogPlayFabCpp, Error, TEXT("You must call GetEntityToken API Method before calling this function."));
    }


    auto HttpRequest = PlayFabRequestHandler::SendRequest(nullptr, TEXT("/CloudScript/UnregisterFunction"), request.toJSONString(), TEXT("X-EntityToken"), entityToken);
    HttpRequest->OnProcessRequestComplete().BindRaw(this, &UPlayFabCloudScriptAPI::OnUnregisterFunctionResult, SuccessDelegate, ErrorDelegate);
    return HttpRequest->ProcessRequest();
}

void UPlayFabCloudScriptAPI::OnUnregisterFunctionResult(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FUnregisterFunctionDelegate SuccessDelegate, FPlayFabErrorDelegate ErrorDelegate)
{
    CloudScriptModels::FEmptyResult outResult;
    FPlayFabCppError errorResult;
    if (PlayFabRequestHandler::DecodeRequest(HttpRequest, HttpResponse, bSucceeded, outResult, errorResult))
    {
        SuccessDelegate.ExecuteIfBound(outResult);
    }
    else
    {
        ErrorDelegate.ExecuteIfBound(errorResult);
    }
}
