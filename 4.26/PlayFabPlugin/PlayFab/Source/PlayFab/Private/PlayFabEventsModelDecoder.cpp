//////////////////////////////////////////////////////
// Copyright (C) Microsoft. 2018. All rights reserved.
//////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////////////////
// Automatically generated cpp file for the play fab models
//
// API: Events
//////////////////////////////////////////////////////////////////////////////////////////////

#include "PlayFabEventsModelDecoder.h"
#include "PlayFabPrivate.h"

//////////////////////////////////////////////////////////////////////////
// Generated PlayFab Events API Functions
//////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////
// PlayStream
//////////////////////////////////////////////////////



///////////////////////////////////////////////////////
// PlayStream Events
//////////////////////////////////////////////////////

FEventsWriteEventsResponse UPlayFabEventsModelDecoder::decodeWriteEventsResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FEventsWriteEventsResponse tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.AssignedEventIds = !(dataObj->HasField("AssignedEventIds")) ? TEXT("") : FString::Join(dataObj->GetStringArrayField("AssignedEventIds"), TEXT(","));

    return tempStruct;
}


