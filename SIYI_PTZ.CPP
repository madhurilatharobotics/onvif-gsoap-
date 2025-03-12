#include "soapH.h"
#include "sdk.h" 
#include "soapStub.h"
#include "stdsoap2.h"
#include "stools.h"
#include "service_context.h"

SIYI_SDK camera("192.168.2.25", 37260);  


SOAP_FMAC5 int SOAP_FMAC6 __tptz__GetServiceCapabilities(struct soap *soap,
    struct _tptz__GetServiceCapabilities *req,
    struct _tptz__GetServiceCapabilitiesResponse &_tptz__GetServiceCapabilitiesResponse)
{
    _tptz__GetServiceCapabilitiesResponse.Capabilities = soap_new_tptz__Capabilities(soap);
    _tptz__GetServiceCapabilitiesResponse.Capabilities->EFlip = soap_new_bool(soap);
    *(_tptz__GetServiceCapabilitiesResponse.Capabilities->EFlip) = true;
    _tptz__GetServiceCapabilitiesResponse.Capabilities->Reverse = soap_new_bool(soap);
    *(_tptz__GetServiceCapabilitiesResponse.Capabilities->Reverse) = true;
    _tptz__GetServiceCapabilitiesResponse.Capabilities->GetCompatibleConfigurations = soap_new_bool(soap);
    *(_tptz__GetServiceCapabilitiesResponse.Capabilities->GetCompatibleConfigurations) = true;
    std::cout << "Function name: " << __func__ << std::endl;
    return SOAP_OK;
}

SOAP_FMAC5 int  __tptz__GetNodes(struct soap *soap,
    struct _tptz__GetNodes *_tptz__GetNodes,
    struct _tptz__GetNodesResponse &_tptz__GetNodesResponse)
{
    std::cout << "Function name: " << __func__ << std::endl;
    return SOAP_OK;
}

SOAP_FMAC5 int  __tptz__GetNode(struct soap *soap,
    struct _tptz__GetNode *_tptz__GetNode,
    struct _tptz__GetNodeResponse &_tptz__GetNodeResponse)
{
    std::cout << "Function name: " << __func__ << std::endl;
    return SOAP_OK;
}

SOAP_FMAC5 int  __tptz__GetConfigurations(struct soap *soap,
    struct _tptz__GetConfigurations *_tptz__GetConfigurations,
    struct _tptz__GetConfigurationsResponse &tptz__GetConfigurationsResponse)
{
    tt__PTZConfiguration* config = soap_new_tt__PTZConfiguration(soap);
    config->token     = soap_strdup(soap, "PTZConf1");
    config->NodeToken = soap_strdup(soap, "PTZNode1");
    config->Name      = soap_strdup(soap, "My PTZ Config");
    config->UseCount  = 1;

    tptz__GetConfigurationsResponse.PTZConfiguration.push_back(config);
    return SOAP_OK;
}

SOAP_FMAC5 int  __tptz__GetConfiguration(struct soap *soap,
    struct  _tptz__GetConfiguration *tptz__GetConfiguration,
    struct _tptz__GetConfigurationResponse &_tptz__GetConfigurationResponse)
{
    std::cout << "Function name: " << __func__ << std::endl;
    return SOAP_OK;
}

SOAP_FMAC5 int  __tptz__SetConfiguration(struct soap *soap,
    struct  _tptz__SetConfiguration *_tptz__SetConfiguration,
    struct _tptz__SetConfigurationResponse &_tptz__SetConfigurationResponse)
{
    std::cout << "Function name: " << __func__ << std::endl;
    return SOAP_OK;
}

SOAP_FMAC5 int  __tptz__GetConfigurationOptions(struct soap *soap,
    struct _tptz__GetConfigurationOptions *req,
    struct _tptz__GetConfigurationOptionsResponse &res)
{
    std::cout << "Function name: " << __func__ << std::endl;
    return SOAP_OK;
}

SOAP_FMAC5 int  __tptz__SendAuxiliaryCommand(struct soap *soap,
    struct _tptz__SendAuxiliaryCommand *req,
    struct _tptz__SendAuxiliaryCommandResponse &res)
{
    std::cout << "Function name: " << __func__ << std::endl;
    return SOAP_OK;
}

SOAP_FMAC5 int  __tptz__GetPresets(struct soap *soap,
    struct _tptz__GetPresets *req,
    struct _tptz__GetPresetsResponse &res)
{
    std::cout << "Function name: " << __func__ << std::endl;
    return SOAP_OK;
}

SOAP_FMAC5 int  __tptz__SetPreset(struct soap *soap,
    struct _tptz__SetPreset *req,
    struct _tptz__SetPresetResponse &res)
{
    std::cout << "Function name: " << __func__ << std::endl;
    return SOAP_OK;
}

SOAP_FMAC5 int  __tptz__RemovePreset(struct soap *soap,
    struct _tptz__RemovePreset *req,
    struct _tptz__RemovePresetResponse &res)
{
    std::cout << "Function name: " << __func__ << std::endl;
    return SOAP_OK;
}

SOAP_FMAC5 int  __tptz__GotoPreset(struct soap *soap,
    struct _tptz__GotoPreset *,
    struct _tptz__GotoPresetResponse &res)
{
    std::cout << "Function name: " << __func__ << std::endl;
    return SOAP_OK;
}

SOAP_FMAC5 int  __tptz__ContinuousMove(struct soap *soap,
    struct _tptz__ContinuousMove *req,
    struct _tptz__ContinuousMoveResponse &response)
{
    std::cout << "Function name: " << __func__ << std::endl;
    if (req->Velocity && req->Velocity->PanTilt) {
        float pan_speed = req->Velocity->PanTilt->x;  // X-axis for yaw (left/right)
        float tilt_speed = req->Velocity->PanTilt->y; // Y-axis for pitch (up/down)

        std::cout << "Received Pan: " << pan_speed << " Tilt: " << tilt_speed << std::endl;

        if (!camera.set_gimbal_speed(pan_speed * 10, tilt_speed * 10)) {
            std::cerr << "Failed to send PTZ move command!" << std::endl;
            return SOAP_FAULT;
        }
    }
    return SOAP_OK;
}

SOAP_FMAC5 int  __tptz__AbsoluteMove(struct soap *soap,
    struct _tptz__AbsoluteMove *,
    struct _tptz__AbsoluteMoveResponse &res)
{
    std::cout << "Function name: " << __func__ << std::endl;
    return SOAP_OK;
}

SOAP_FMAC5 int  __tptz__RelativeMove(struct soap *soap,
    struct _tptz__RelativeMove *,
    struct _tptz__RelativeMoveResponse &res)
{
    std::cout << "Function name: " << __func__ << std::endl;
    return SOAP_OK;
}

SOAP_FMAC5 int   __tptz__GetPresetTours(struct soap *soap,
    struct _tptz__GetPresetTours *req,
    struct _tptz__GetPresetToursResponse &res)
{
    std::cout << "Function name: " << __func__ << std::endl;
    return SOAP_OK;
}

SOAP_FMAC5 int  __tptz__Stop(struct soap *soap,
    struct _tptz__Stop *req,
    struct _tptz__StopResponse &res)
{
    std::cout << "Function name: " << __func__ << std::endl;
    return SOAP_OK;
}

SOAP_FMAC5 int  __tptz__GeoMove(struct soap *soap,
    struct _tptz__GeoMove *req,
    struct _tptz__GeoMoveResponse &res)
{
    std::cout << "Function name: " << __func__ << std::endl;
    return SOAP_OK;
}

SOAP_FMAC5 int   __tptz__MoveAndStartTracking(
    struct soap *soap,
   struct  _tptz__MoveAndStartTracking *req,
   struct  _tptz__MoveAndStartTrackingResponse &res)
{
    return SOAP_OK;
}

SOAP_FMAC5 int  __tptz__GetStatus(struct soap *soap,
    struct _tptz__GetStatus *req,
   struct _tptz__GetStatusResponse & _tptz__res)
{
    return SOAP_OK;
}

SOAP_FMAC5 int  __tptz__GotoHomePosition(struct soap *soap,
    struct _tptz__GotoHomePosition *_tptz__GotoHomePosition,
    struct _tptz__GotoHomePositionResponse &tptz__GotoHomePositionResponse)
{
    std::cout << "Function name: " << __func__ << std::endl;
    return SOAP_OK;
}

SOAP_FMAC5 int  __tptz__SetHomePosition(struct soap *soap,
    struct _tptz__SetHomePosition *_tptz__SetHomePosition,
    struct _tptz__SetHomePositionResponse &_tptz__SetHomePositionResponse)
{
    std::cout << "Function name: " << __func__ << std::endl;
    return SOAP_OK;
}

SOAP_FMAC5 int __tptz__GetPresetTour(struct soap *soap,
    struct _tptz__GetPresetTour *_tptz__GetPresetTour,
    struct _tptz__GetPresetTourResponse &_tptz__GetPresetTourResponse)
{
    std::cout << "Function name: " << __func__ << std::endl;
    return SOAP_OK;
}

SOAP_FMAC5 int  __tptz__GetPresetTourOptions(struct soap *soap,
    struct _tptz__GetPresetTourOptions *_tptz__GetPresetTourOptions,
    struct _tptz__GetPresetTourOptionsResponse &_tptz__GetPresetTourOptionsResponse)
{
    std::cout << "Function name: " << __func__ << std::endl;
    return SOAP_OK;
}

SOAP_FMAC5 int  __tptz__CreatePresetTour(struct soap *soap,
    struct _tptz__CreatePresetTour *_tptz__CreatePresetTour,
    struct _tptz__CreatePresetTourResponse &_tptz__CreatePresetTourResponse)
{
    std::cout << "Function name: " << __func__ << std::endl;
    return SOAP_OK;
}

SOAP_FMAC5 int  __tptz__ModifyPresetTour(struct soap *soap,
    struct _tptz__ModifyPresetTour *_tptz__ModifyPresetTour,
    struct _tptz__ModifyPresetTourResponse &_tptz__ModifyPresetTourResponse)
{
    std::cout << "Function name: " << __func__ << std::endl;
    return SOAP_OK;
}

SOAP_FMAC5 int  __tptz__OperatePresetTour(struct soap *soap,
    struct _tptz__OperatePresetTour *_tptz__OperatePresetTour,
    struct _tptz__OperatePresetTourResponse &_tptz__OperatePresetTourResponse)
{
    std::cout << "Function name: " << __func__ << std::endl;
    return SOAP_OK;
}

SOAP_FMAC5 int __tptz__RemovePresetTour(struct soap *soap,
    struct _tptz__RemovePresetTour *_tptz__RemovePresetTour,
    struct _tptz__RemovePresetTourResponse &_tptz__RemovePresetTourResponse)
{
    std::cout << "Function name: " << __func__ << std::endl;
    return SOAP_OK;
}

SOAP_FMAC5 int  __tptz__GetCompatibleConfigurations(struct soap *soap,
    struct _tptz__GetCompatibleConfigurations *_tptz__GetCompatibleConfigurations,
    struct _tptz__GetCompatibleConfigurationsResponse &_tptz__GetCompatibleConfigurationsResponse)
{
    std::cout << "Function name: " << __func__ << std::endl;
    return SOAP_OK;
}





