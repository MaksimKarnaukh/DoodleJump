// Implemented as a singleton class.

#ifndef DOODLEJUMP_CAMERA_H
#define DOODLEJUMP_CAMERA_H

#include "utility"
#include "cmath"

namespace logic {
    namespace utility {

        class Camera {

            int windowWidth = 640; // width of out window in pixels
            int windowHeight = 960; // height of out window in pixels

            float shiftValue = 0.0f; // value that indicates how much we need to decrease our y-coordinate to project near the origin.

            float shiftBorder = 0.6f; // value at which we start increasing the shiftValue

            float leftBound = 0.0f; // leftmost logic coordinate (left boundary)
            float rightBound = 1.0f; // rightmost logic coordinate (right boundary)
            float lowerBound = 0.0f; // lowermost logic coordinate (lower boundary)

            /**
            * @function : Camera
            * Constructor for a Camera.
            */
            Camera();

        public:

            /**
            * @function : setWindowWidth
            * Setter function for the windowWidth data member.
            * @param width (int) : value that we want to give to windowWidth.
            */
            void setWindowWidth(int width) {
                windowWidth = width;
            }

            /**
            * @function : setWindowHeight
            * Setter function for the windowHeight data member.
            * @param height (int) : value that we want to give to windowHeight.
            */
            void setWindowHeight(int height) {
                windowHeight = height;
            }

            /**
            * @function : setShiftValue
            * Setter function for the shiftValue data member.
            * @param shift (float) : value that we want to give to shiftValue.
            */
            void setShiftValue(float shift) {
                shiftValue = shift;
            }

            /**
            * @function : setLeftBound
            * Setter function for the leftBound data member.
            * @param LeftBound (float) : value that we want to give to leftBound.
            */
            void setLeftBound(const float LeftBound) {
                leftBound = LeftBound;
            }

            /**
            * @function : setRightBound
            * Setter function for the rightBound data member.
            * @param RightBound (float) : value that we want to give to rightBound.
            */
            void setRightBound(const float RightBound) {
                rightBound = RightBound;
            }

            /**
            * @function : setLowerBound
            * Setter function for the lowerBound data member.
            * @param LowerBound (float) : value that we want to give to lowerBound.
            */
            void setLowerBound(const float LowerBound) {
                lowerBound = LowerBound;
            }

            /**
            * @function : setShiftBorder
            * Setter function for the shiftBorder data member.
            * @param ShiftBorder (float) : value that we want to give to shiftBorder.
            */
            void setShiftBorder(const float ShiftBorder) {
                shiftBorder = ShiftBorder;
            }

            /**
            * @function : getWindowWidth
            * Getter function for the windowWidth data member.
            * @return (int) : this->windowWidth
            */
            int getWindowWidth() const {
                return windowWidth;
            }

            /**
            * @function : getWindowHeight
            * Getter function for the windowHeight data member.
            * @return (int) : this->windowHeight
            */
            int getWindowHeight() const {
                return windowHeight;
            }

            /**
            * @function : getShiftValue
            * Getter function for the shiftValue data member.
            * @return (float) : this->shiftValue
            */
            float getShiftValue() const {
                return shiftValue;
            }

            /**
            * @function : getLeftBound
            * Getter function for the leftBound data member.
            * @return (float) : this->leftBound
            */
            float getLeftBound() const {
                return leftBound;
            }

            /**
            * @function : getRightBound
            * Getter function for the rightBound data member.
            * @return (float) : this->rightBound
            */
            float getRightBound() const {
                return rightBound;
            }

            /**
            * @function : getLowerBound
            * Getter function for the lowerBound data member.
            * @return (float) : this->lowerBound
            */
            float getLowerBound() const {
                return lowerBound;
            }

            /**
            * @function : getShiftBorder
            * Getter function for the shiftBorder data member.
            * @return (float) : this->shiftBorder
            */
            float getShiftBorder() const {
                return shiftBorder;
            }

        public:

            static Camera& Instance();

            /**
            * @function : projectCoordinates
            * Projects the logic coordinates (x and y) to pixel coordinates on the window.
            * @param x (float) : logic x-coordinate.
            * @param y (float) : logic y-coordinate.
            * @return (std::pair<int,int>): pair (x,y) of pixel coordinates.
            */
            std::pair<int,int> projectCoordinates(float x, float y) const;

        public:

            Camera(const Camera &) = delete;
            Camera(const Camera &&) = delete;

            Camera& operator=(const Camera &) = delete;
            Camera& operator=(const Camera &&) = delete;

        };
    }
}



#endif //DOODLEJUMP_CAMERA_H
