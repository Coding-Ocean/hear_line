#include"libOne.h"
#define HEART_
#ifdef HEART_
void getShapePos(float t, float& x, float& y) {
    x = pow(sin(t), 3);
    y = (13 * cos(t) - 5 * cos(2 * t) - 2 * cos(3 * t) - cos(4 * t)) / 16;
}
#else
void getShapePos(float t, float& x, float& y) {
    x = sin(t);
    y = cos(t);
}
#endif
void gmain() {
    window(1920, 1080, full);
    float cx = width / 2;
    float cy = height / 2;
    float sx, sy, ex, ey;
#ifdef HEART_
    float radius = 200;
#else
    float radius = 120;
#endif
    float deg = 0, inc = 1;
    float limmit = 0;
    angleMode(DEGREES);
    ShowCursor(FALSE);
    while (notQuit) {
        limmit += 1;
        if (limmit >= 360) {
            limmit = 0;
        }
        clear(1);
        //x,y���W
        stroke(100);
        strokeWeight(2);
        line(cx - radius, cy, cx + radius, cy);
        line(cx, cy - radius, cx, cy + radius);
        //limmit�̊p�x�܂Ńn�[�g��line��`��
        deg = 0;
        getShapePos(deg, sx, sy);//�n�_
        while (deg <= limmit) {
            deg += inc;
            getShapePos(deg, ex, ey);//�I�_
            strokeWeight(4);
            //�����W
            stroke(255, 128, 128);
            line(cx + sx * radius, deg - inc, cx + ex * radius, deg);
            //�����W
            stroke(128, 255, 128);
            line(cx/3 + deg - inc, cy - sy * radius, cx/3 + deg, cy - ey * radius);
            //�n�[�g
            strokeWeight(30);
            stroke(255, 128, 255);
            line(cx + sx * radius, cy - sy * radius, cx + ex * radius, cy - ey * radius);
            //�I�_������line�̎n�_�ɂ���
            sx = ex;
            sy = ey;
        }
        //x���W�����܂ŐL�΂�
        strokeWeight(2);
        line(cx + sx * radius, deg - inc, cx + sx * radius, height);
        //y���W���E�܂ŐL�΂�
        line(cx / 3 + deg, cy - sy * radius, width, cy - sy * radius);
        //���̕\��
#ifdef HEART_
        fill(255);
        text("x = pow(sin(t), 3)", cx+radius, 180);
        text("y = (13 * cos(t) - 5 * cos(2 * t) - 2 * cos(3 * t) - cos(4 * t))/16",200,cy+radius+100);
#endif
    }
    ShowCursor(TRUE);
}