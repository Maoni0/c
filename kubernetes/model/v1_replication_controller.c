#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_replication_controller.h"



v1_replication_controller_t *v1_replication_controller_create(
    char *api_version,
    char *kind,
    v1_object_meta_t *metadata,
    v1_replication_controller_spec_t *spec,
    v1_replication_controller_status_t *status
    ) {
    v1_replication_controller_t *v1_replication_controller_local_var = malloc(sizeof(v1_replication_controller_t));
    if (!v1_replication_controller_local_var) {
        return NULL;
    }
    v1_replication_controller_local_var->api_version = api_version;
    v1_replication_controller_local_var->kind = kind;
    v1_replication_controller_local_var->metadata = metadata;
    v1_replication_controller_local_var->spec = spec;
    v1_replication_controller_local_var->status = status;

    return v1_replication_controller_local_var;
}


void v1_replication_controller_free(v1_replication_controller_t *v1_replication_controller) {
    if(NULL == v1_replication_controller){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_replication_controller->api_version) {
        free(v1_replication_controller->api_version);
        v1_replication_controller->api_version = NULL;
    }
    if (v1_replication_controller->kind) {
        free(v1_replication_controller->kind);
        v1_replication_controller->kind = NULL;
    }
    if (v1_replication_controller->metadata) {
        v1_object_meta_free(v1_replication_controller->metadata);
        v1_replication_controller->metadata = NULL;
    }
    if (v1_replication_controller->spec) {
        v1_replication_controller_spec_free(v1_replication_controller->spec);
        v1_replication_controller->spec = NULL;
    }
    if (v1_replication_controller->status) {
        v1_replication_controller_status_free(v1_replication_controller->status);
        v1_replication_controller->status = NULL;
    }
    free(v1_replication_controller);
}

cJSON *v1_replication_controller_convertToJSON(v1_replication_controller_t *v1_replication_controller) {
    cJSON *item = cJSON_CreateObject();

    // v1_replication_controller->api_version
    if(v1_replication_controller->api_version) {
    if(cJSON_AddStringToObject(item, "apiVersion", v1_replication_controller->api_version) == NULL) {
    goto fail; //String
    }
    }


    // v1_replication_controller->kind
    if(v1_replication_controller->kind) {
    if(cJSON_AddStringToObject(item, "kind", v1_replication_controller->kind) == NULL) {
    goto fail; //String
    }
    }


    // v1_replication_controller->metadata
    if(v1_replication_controller->metadata) {
    cJSON *metadata_local_JSON = v1_object_meta_convertToJSON(v1_replication_controller->metadata);
    if(metadata_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "metadata", metadata_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_replication_controller->spec
    if(v1_replication_controller->spec) {
    cJSON *spec_local_JSON = v1_replication_controller_spec_convertToJSON(v1_replication_controller->spec);
    if(spec_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "spec", spec_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_replication_controller->status
    if(v1_replication_controller->status) {
    cJSON *status_local_JSON = v1_replication_controller_status_convertToJSON(v1_replication_controller->status);
    if(status_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "status", status_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1_replication_controller_t *v1_replication_controller_parseFromJSON(cJSON *v1_replication_controllerJSON){

    v1_replication_controller_t *v1_replication_controller_local_var = NULL;

    // define the local variable for v1_replication_controller->metadata
    v1_object_meta_t *metadata_local_nonprim = NULL;

    // define the local variable for v1_replication_controller->spec
    v1_replication_controller_spec_t *spec_local_nonprim = NULL;

    // define the local variable for v1_replication_controller->status
    v1_replication_controller_status_t *status_local_nonprim = NULL;

    // v1_replication_controller->api_version
    cJSON *api_version = cJSON_GetObjectItemCaseSensitive(v1_replication_controllerJSON, "apiVersion");
    if (api_version) { 
    if(!cJSON_IsString(api_version))
    {
    goto end; //String
    }
    }

    // v1_replication_controller->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(v1_replication_controllerJSON, "kind");
    if (kind) { 
    if(!cJSON_IsString(kind))
    {
    goto end; //String
    }
    }

    // v1_replication_controller->metadata
    cJSON *metadata = cJSON_GetObjectItemCaseSensitive(v1_replication_controllerJSON, "metadata");
    if (metadata) { 
    metadata_local_nonprim = v1_object_meta_parseFromJSON(metadata); //nonprimitive
    }

    // v1_replication_controller->spec
    cJSON *spec = cJSON_GetObjectItemCaseSensitive(v1_replication_controllerJSON, "spec");
    if (spec) { 
    spec_local_nonprim = v1_replication_controller_spec_parseFromJSON(spec); //nonprimitive
    }

    // v1_replication_controller->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(v1_replication_controllerJSON, "status");
    if (status) { 
    status_local_nonprim = v1_replication_controller_status_parseFromJSON(status); //nonprimitive
    }


    v1_replication_controller_local_var = v1_replication_controller_create (
        api_version ? strdup(api_version->valuestring) : NULL,
        kind ? strdup(kind->valuestring) : NULL,
        metadata ? metadata_local_nonprim : NULL,
        spec ? spec_local_nonprim : NULL,
        status ? status_local_nonprim : NULL
        );

    return v1_replication_controller_local_var;
end:
    if (metadata_local_nonprim) {
        v1_object_meta_free(metadata_local_nonprim);
        metadata_local_nonprim = NULL;
    }
    if (spec_local_nonprim) {
        v1_replication_controller_spec_free(spec_local_nonprim);
        spec_local_nonprim = NULL;
    }
    if (status_local_nonprim) {
        v1_replication_controller_status_free(status_local_nonprim);
        status_local_nonprim = NULL;
    }
    return NULL;

}
