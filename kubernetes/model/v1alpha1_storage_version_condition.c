#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1alpha1_storage_version_condition.h"



v1alpha1_storage_version_condition_t *v1alpha1_storage_version_condition_create(
    char *last_transition_time,
    char *message,
    long observed_generation,
    char *reason,
    char *status,
    char *type
    ) {
    v1alpha1_storage_version_condition_t *v1alpha1_storage_version_condition_local_var = malloc(sizeof(v1alpha1_storage_version_condition_t));
    if (!v1alpha1_storage_version_condition_local_var) {
        return NULL;
    }
    v1alpha1_storage_version_condition_local_var->last_transition_time = last_transition_time;
    v1alpha1_storage_version_condition_local_var->message = message;
    v1alpha1_storage_version_condition_local_var->observed_generation = observed_generation;
    v1alpha1_storage_version_condition_local_var->reason = reason;
    v1alpha1_storage_version_condition_local_var->status = status;
    v1alpha1_storage_version_condition_local_var->type = type;

    return v1alpha1_storage_version_condition_local_var;
}


void v1alpha1_storage_version_condition_free(v1alpha1_storage_version_condition_t *v1alpha1_storage_version_condition) {
    if(NULL == v1alpha1_storage_version_condition){
        return ;
    }
    listEntry_t *listEntry;
    if (v1alpha1_storage_version_condition->last_transition_time) {
        free(v1alpha1_storage_version_condition->last_transition_time);
        v1alpha1_storage_version_condition->last_transition_time = NULL;
    }
    if (v1alpha1_storage_version_condition->message) {
        free(v1alpha1_storage_version_condition->message);
        v1alpha1_storage_version_condition->message = NULL;
    }
    if (v1alpha1_storage_version_condition->reason) {
        free(v1alpha1_storage_version_condition->reason);
        v1alpha1_storage_version_condition->reason = NULL;
    }
    if (v1alpha1_storage_version_condition->status) {
        free(v1alpha1_storage_version_condition->status);
        v1alpha1_storage_version_condition->status = NULL;
    }
    if (v1alpha1_storage_version_condition->type) {
        free(v1alpha1_storage_version_condition->type);
        v1alpha1_storage_version_condition->type = NULL;
    }
    free(v1alpha1_storage_version_condition);
}

cJSON *v1alpha1_storage_version_condition_convertToJSON(v1alpha1_storage_version_condition_t *v1alpha1_storage_version_condition) {
    cJSON *item = cJSON_CreateObject();

    // v1alpha1_storage_version_condition->last_transition_time
    if(v1alpha1_storage_version_condition->last_transition_time) {
    if(cJSON_AddStringToObject(item, "lastTransitionTime", v1alpha1_storage_version_condition->last_transition_time) == NULL) {
    goto fail; //Date-Time
    }
    }


    // v1alpha1_storage_version_condition->message
    if(v1alpha1_storage_version_condition->message) {
    if(cJSON_AddStringToObject(item, "message", v1alpha1_storage_version_condition->message) == NULL) {
    goto fail; //String
    }
    }


    // v1alpha1_storage_version_condition->observed_generation
    if(v1alpha1_storage_version_condition->observed_generation) {
    if(cJSON_AddNumberToObject(item, "observedGeneration", v1alpha1_storage_version_condition->observed_generation) == NULL) {
    goto fail; //Numeric
    }
    }


    // v1alpha1_storage_version_condition->reason
    if (!v1alpha1_storage_version_condition->reason) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "reason", v1alpha1_storage_version_condition->reason) == NULL) {
    goto fail; //String
    }


    // v1alpha1_storage_version_condition->status
    if (!v1alpha1_storage_version_condition->status) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "status", v1alpha1_storage_version_condition->status) == NULL) {
    goto fail; //String
    }


    // v1alpha1_storage_version_condition->type
    if (!v1alpha1_storage_version_condition->type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "type", v1alpha1_storage_version_condition->type) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1alpha1_storage_version_condition_t *v1alpha1_storage_version_condition_parseFromJSON(cJSON *v1alpha1_storage_version_conditionJSON){

    v1alpha1_storage_version_condition_t *v1alpha1_storage_version_condition_local_var = NULL;

    // v1alpha1_storage_version_condition->last_transition_time
    cJSON *last_transition_time = cJSON_GetObjectItemCaseSensitive(v1alpha1_storage_version_conditionJSON, "lastTransitionTime");
    if (last_transition_time) { 
    if(!cJSON_IsString(last_transition_time) && !cJSON_IsNull(last_transition_time))
    {
    goto end; //DateTime
    }
    }

    // v1alpha1_storage_version_condition->message
    cJSON *message = cJSON_GetObjectItemCaseSensitive(v1alpha1_storage_version_conditionJSON, "message");
    if (message) { 
    if(!cJSON_IsString(message))
    {
    goto end; //String
    }
    }

    // v1alpha1_storage_version_condition->observed_generation
    cJSON *observed_generation = cJSON_GetObjectItemCaseSensitive(v1alpha1_storage_version_conditionJSON, "observedGeneration");
    if (observed_generation) { 
    if(!cJSON_IsNumber(observed_generation))
    {
    goto end; //Numeric
    }
    }

    // v1alpha1_storage_version_condition->reason
    cJSON *reason = cJSON_GetObjectItemCaseSensitive(v1alpha1_storage_version_conditionJSON, "reason");
    if (!reason) {
        goto end;
    }

    
    if(!cJSON_IsString(reason))
    {
    goto end; //String
    }

    // v1alpha1_storage_version_condition->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(v1alpha1_storage_version_conditionJSON, "status");
    if (!status) {
        goto end;
    }

    
    if(!cJSON_IsString(status))
    {
    goto end; //String
    }

    // v1alpha1_storage_version_condition->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(v1alpha1_storage_version_conditionJSON, "type");
    if (!type) {
        goto end;
    }

    
    if(!cJSON_IsString(type))
    {
    goto end; //String
    }


    v1alpha1_storage_version_condition_local_var = v1alpha1_storage_version_condition_create (
        last_transition_time && !cJSON_IsNull(last_transition_time) ? strdup(last_transition_time->valuestring) : NULL,
        message ? strdup(message->valuestring) : NULL,
        observed_generation ? observed_generation->valuedouble : 0,
        strdup(reason->valuestring),
        strdup(status->valuestring),
        strdup(type->valuestring)
        );

    return v1alpha1_storage_version_condition_local_var;
end:
    return NULL;

}
