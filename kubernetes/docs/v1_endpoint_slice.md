# v1_endpoint_slice_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**address_type** | **char \*** | addressType specifies the type of address carried by this EndpointSlice. All addresses in this slice must be the same type. This field is immutable after creation. The following address types are currently supported: * IPv4: Represents an IPv4 Address. * IPv6: Represents an IPv6 Address. * FQDN: Represents a Fully Qualified Domain Name.   | 
**api_version** | **char \*** | APIVersion defines the versioned schema of this representation of an object. Servers should convert recognized schemas to the latest internal value, and may reject unrecognized values. More info: https://git.k8s.io/community/contributors/devel/sig-architecture/api-conventions.md#resources | [optional] 
**endpoints** | [**list_t**](v1_endpoint.md) \* | endpoints is a list of unique endpoints in this slice. Each slice may include a maximum of 1000 endpoints. | 
**kind** | **char \*** | Kind is a string value representing the REST resource this object represents. Servers may infer this from the endpoint the client submits requests to. Cannot be updated. In CamelCase. More info: https://git.k8s.io/community/contributors/devel/sig-architecture/api-conventions.md#types-kinds | [optional] 
**metadata** | [**v1_object_meta_t**](v1_object_meta.md) \* |  | [optional] 
**ports** | [**list_t**](discovery_v1_endpoint_port.md) \* | ports specifies the list of network ports exposed by each endpoint in this slice. Each port must have a unique name. When ports is empty, it indicates that there are no defined ports. When a port is defined with a nil port value, it indicates \&quot;all ports\&quot;. Each slice may include a maximum of 100 ports. | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


