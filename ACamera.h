#ifndef ACAMERA_H
#define ACAMERA_H

#include <QVector3D>
#include <QMatrix4x4>
#include <QKeyEvent>

// Defines several possible options for camera movement. Used as abstraction to stay away from window-system specific input methods
enum Camera_Movement {
  FORWARD,
  BACKWARD,
  LEFT,
  RIGHT,
  UP,
  DOWN
};

// Default camera values
const float YAW = -90.0f;
const float PITCH = 0.0f;
const float SPEED = 1.0f;
const float SENSITIVITY = 0.0001f;
const float ZOOM = 45.0f;

class ACamera {
public:
    ACamera(QVector3D position = QVector3D(0.0f, 0.0f, 0.0f), QVector3D up = QVector3D(0.0f, 1.0f, 0.0f),
    float yaw = YAW, float pitch = PITCH);
    ~ACamera();

    QMatrix4x4 getViewMatrix();
    void processMouseMovement(float xoffset, float yoffset, bool constraintPitch = true);
    void processMouseScroll(float yoffset);
    void processInput(float dt);

    QVector3D position;// 摄像机位置
    QVector3D worldUp; // 上向量
    QVector3D front;// 摄像机方向向量  \/

    QVector3D up; // 上轴
    QVector3D right; // 右轴

    //Eular Angles
    float picth; // 俯仰角
    float yaw; // 偏航角

    //Camera options
    float movementSpeed;
    float mouseSensitivity;
    float zoom;

    //Keyboard multi-touch
    bool keys[1024];
private:
    void updateCameraVectors();
    void processKeyboard(Camera_Movement direction, float deltaTime);
};

#endif // ACAMERA_H
