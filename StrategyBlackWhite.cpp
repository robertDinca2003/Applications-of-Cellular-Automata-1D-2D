//
// Created by robert on 21.05.2024.
//

#include "StrategyBlackWhite.h"


void StrategyBlackWhite::readData(std::vector<std::vector<int>> &binaryMatrix, int opt) {
    std::string fileName;
    if (opt)
        fileName = "bwInputDe.jpg";
    else
        fileName = "bwInputEn.jpg";
    cv::Mat grayImage = cv::imread(fileName, cv::IMREAD_GRAYSCALE);
    cv::Mat binaryImage;
    cv::threshold(grayImage, binaryImage, 127, 255, cv::THRESH_BINARY);

    binaryMatrix.resize(binaryImage.rows);
    for (int i = 0; i < binaryImage.rows; i++)
        binaryMatrix[i].resize(binaryImage.cols);

    for (int i = 0; i < binaryImage.rows; i++) {
        for (int j = 0; j < binaryImage.cols; j++)
            binaryMatrix[i][j] = (binaryImage.at<uint8_t>(i, j) == 0) ? 1 : 0;
    }

    for (const auto &row: binaryMatrix) {
        for (int val: row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }

}

void StrategyBlackWhite::doEncryption() {
    std::vector<std::vector<int>> matrix;
    std::vector<std::vector<int>> outputMat;
    readData(matrix, 0);
    ElementaryRule rule(30, matrix[0].size(), matrix.size() * 3 / 2 + 1);
    rule.GenerateToMaxDepth();
    outputMat.resize((int) matrix.size());
    for (size_t i = 0; i < matrix.size(); i++)
        outputMat[i].resize(matrix[0].size());

    for (size_t i = 0; i < matrix.size(); i++)
        for (size_t j = 0; j < matrix[0].size(); j++) {
            outputMat[i][j] = matrix[i][j] ^ rule.getElement(matrix.size() / 2 + i, j);
        }

    std::vector<std::vector<int>> binaryOutput;
    binaryOutput.resize(outputMat.size() * 2);
    for (size_t i = 0; i < outputMat.size() * 2; i++)
        binaryOutput[i].resize(outputMat[0].size() * 2);

    for (size_t i = 0; i < binaryOutput.size(); i++) {
        for (size_t j = 0; j < binaryOutput[i].size(); j++) {
            if (i % 2 == 0 && j % 2 == 0) {
                if (outputMat[i / 2][j / 2]) {
                    binaryOutput[i][j] = 1;
                    binaryOutput[i][j + 1] = 0;
                    binaryOutput[i + 1][j] = 0;
                    binaryOutput[i + 1][j + 1] = 1;
                } else {
                    binaryOutput[i][j] = 0;
                    binaryOutput[i][j + 1] = 1;
                    binaryOutput[i + 1][j] = 1;
                    binaryOutput[i + 1][j + 1] = 0;
                }
            }
        }
    }

    cv::Mat image(binaryOutput.size(), binaryOutput[0].size(), CV_8UC4);

    for (size_t i = 0; i < binaryOutput.size(); i++)
        for (size_t j = 0; j < binaryOutput[0].size(); j++)
            if (i % 2 == 0 && j % 2 == 0) {
                if (rule.getElement(i / 2 + matrix.size() / 2, j / 2)) {
                    image.at<cv::Vec4b>(i, j) = cv::Vec4b(255, 255, 255, 0);
                    image.at<cv::Vec4b>(i, j + 1) = cv::Vec4b(0, 0, 0, 255);
                    image.at<cv::Vec4b>(i + 1, j) = cv::Vec4b(0, 0, 0, 255);
                    image.at<cv::Vec4b>(i + 1, j + 1) = cv::Vec4b(255, 255, 255, 0);

                } else {
                    image.at<cv::Vec4b>(i, j) = cv::Vec4b(0, 0, 0, 255);
                    image.at<cv::Vec4b>(i, j + 1) = cv::Vec4b(255, 255, 255, 0);
                    image.at<cv::Vec4b>(i + 1, j) = cv::Vec4b(255, 255, 255, 0);
                    image.at<cv::Vec4b>(i + 1, j + 1) = cv::Vec4b(0, 0, 0, 255);

                }

            }
    cv::imwrite("share1Encrypt.png", image);

    for (size_t i = 0; i < binaryOutput.size(); i++)
        for (size_t j = 0; j < binaryOutput[0].size(); j++)
            if (i % 2 == 0 && j % 2 == 0) {
                if (matrix[i / 2][j / 2]) {
                    if (rule.getElement(i / 2 + matrix.size() / 2, j / 2)) {
                        image.at<cv::Vec4b>(i, j) = cv::Vec4b(0, 0, 0, 255);
                        image.at<cv::Vec4b>(i, j + 1) = cv::Vec4b(255, 255, 255, 0);
                        image.at<cv::Vec4b>(i + 1, j) = cv::Vec4b(255, 255, 255, 0);
                        image.at<cv::Vec4b>(i + 1, j + 1) = cv::Vec4b(0, 0, 0, 255);
                    } else {
                        image.at<cv::Vec4b>(i, j) = cv::Vec4b(255, 255, 255, 0);
                        image.at<cv::Vec4b>(i, j + 1) = cv::Vec4b(0, 0, 0, 255);
                        image.at<cv::Vec4b>(i + 1, j) = cv::Vec4b(0, 0, 0, 255);
                        image.at<cv::Vec4b>(i + 1, j + 1) = cv::Vec4b(255, 255, 255, 0);
                    }


                } else {
                    if (rule.getElement(i / 2 + matrix.size() / 2, j / 2)) {
                        image.at<cv::Vec4b>(i, j) = cv::Vec4b(255, 255, 255, 0);
                        image.at<cv::Vec4b>(i, j + 1) = cv::Vec4b(0, 0, 0, 255);
                        image.at<cv::Vec4b>(i + 1, j) = cv::Vec4b(0, 0, 0, 255);
                        image.at<cv::Vec4b>(i + 1, j + 1) = cv::Vec4b(255, 255, 255, 0);
                    } else {
                        image.at<cv::Vec4b>(i, j) = cv::Vec4b(0, 0, 0, 255);
                        image.at<cv::Vec4b>(i, j + 1) = cv::Vec4b(255, 255, 255, 0);
                        image.at<cv::Vec4b>(i + 1, j) = cv::Vec4b(255, 255, 255, 0);
                        image.at<cv::Vec4b>(i + 1, j + 1) = cv::Vec4b(0, 0, 0, 255);
                    }

                }

            }

    cv::imwrite("share2Encrypt.png", image);
    cv::imwrite("bwInputDe.jpg", image);


}

void StrategyBlackWhite::doDecryption() {
    std::vector<std::vector<int>> matrix;
//    std::vector<std::vector<int>> outputMat;
    readData(matrix, 1);
    ElementaryRule rule(30, matrix[0].size() / 2, matrix.size() * 3 / 4 + 1);
    rule.GenerateToMaxDepth();
    cv::Mat image(matrix.size() / 2, matrix[0].size() / 2, CV_8UC1);

    for (size_t i = 0; i < matrix.size(); i++)
        for (size_t j = 0; j < matrix[0].size(); j++) {
            if (i % 2 == 0 && j % 2 == 0) {
                if (matrix[i][j] == 1) {
                    if (rule.getElement(i / 2 + matrix.size() / 4, j / 2) == 1) {
//0
                        image.at<uint8_t>(i / 2, j / 2) = 0;
                    } else {
// 1
                        image.at<uint8_t>(i / 2, j / 2) = 255;
                    }
                } else {
                    if (rule.getElement(i / 2 + matrix.size() / 4, j / 2) == 1) {
// 1
                        image.at<uint8_t>(i / 2, j / 2) = 255;
                    } else {
// 0
                        image.at<uint8_t>(i / 2, j / 2) = 0;
                    }
                }

            }
        }
    std::cout << "I AM HERE\n";

    cv::imwrite("decryptedImage.jpg", image);
    cv::imwrite("bwInputEn.jpg", image);
}


