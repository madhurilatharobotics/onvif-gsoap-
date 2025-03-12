# onvif-gsoap-
commands for onvif gsoap 
in onvif developed code folder
1) wsdl2h -O4 -P -x -o onvif.h -t /usr/share/gsoap/WS/typemap.dat https://www.onvif.org/onvif/ver10/device/wsdl/devicemgmt.wsdl https://www.onvif.org/ver10/media/wsdl/media.wsdl
2) soapcpp2 -2 -I /usr/share/gsoap/import onvif.h
3) c++ -o siyi_camera siyi.cpp siyi_media.cpp siyi_mgmt.cpp soapC.cpp soapServer.cpp -lgsoap++ -I/usr/share/gsoap -lpthread
 in case if c++ not found then give command sudo apt install g++
