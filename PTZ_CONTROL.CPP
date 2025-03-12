#include <iostream>
#include <thread>
#include <chrono>
#include <iomanip>
#include "sdk.h"  // Include SIYI SDK header

using namespace std;
using namespace std::this_thread;  
using namespace std::chrono;       

void show_menu() {
    cout << "\n--- PTZ Control Menu ---" << endl;
    cout << "1. Move Left (Yaw -30)" << endl;
    cout << "2. Move Right (Yaw +30)" << endl;
    cout << "3. Move Up (Pitch +20)" << endl;
    cout << "4. Move Down (Pitch -20)" << endl;
    cout << "5. Zoom In" << endl;
    cout << "6. Zoom Out" << endl;
    cout << "7. Stop Zoom" << endl;
    cout << "8. Stop PTZ Movement" << endl;
    cout << "9. Exit" << endl;
    cout << "Choose an option: ";

    
}

int main() {
    SIYI_SDK camera("192.168.2.25", 37260);  // Initialize SDK with correct IP and Port
    int choice;

    while (true) {
        show_menu();
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Moving Left..." << endl;
                if (!camera.set_gimbal_speed(-10, 0))
                    cout << "Failed to move left!" << endl;
                break;
            case 2:
                cout << "Moving Right..." << endl;
                if (!camera.set_gimbal_speed(10, 0))
                    cout << "Failed to move right!" << endl;
                break;
            case 3:
                cout << "Moving Up..." << endl;
                if (!camera.set_gimbal_speed(0, 5))
                    cout << "Failed to move up!" << endl;
                break;
            case 4:
                cout << "Moving Down..." << endl;
                if (!camera.set_gimbal_speed(0, -5))
                    cout << "Failed to move down!" << endl;
                break;
            case 5:
                cout << "Zooming In..." << endl;
                if (!camera.request_zoom_in())
                    cout << "Failed to zoom in!" << endl;
                sleep_for(seconds(2));  // Zoom for 2 seconds
                camera.request_zoom_halt();
                break;
            case 6:
                cout << "Zooming Out..." << endl;
                if (!camera.request_zoom_out())
                    cout << "Failed to zoom out!" << endl;
                sleep_for(seconds(2));  // Zoom for 2 seconds
                camera.request_zoom_halt();
                break;
            case 7:
                cout << "Stopping Zoom..." << endl;
                camera.request_zoom_halt();
                break;
            case 8:
                cout << "Stopping PTZ Movement..." << endl;
                camera.set_gimbal_speed(0, 0);
                break;
            case 9:
                cout << "Exiting Program..." << endl;
                return 0;
            default:
                cout << "Invalid choice, please try again." << endl;
        }
    }

    return 0;
}
