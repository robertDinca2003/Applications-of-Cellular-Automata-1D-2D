//
// Created by robert on 21.05.2024.
//

#ifndef OOP_STRATEGYCOLOR_H
#define OOP_STRATEGYCOLOR_H

#include <opencv2/opencv.hpp>
#include "ImageEncryptionStrategy.h"
#include "ElementaryRule.h"
#include <vector>

class StrategyColor : public ImageEncryptionStrategy {

    void generateChannelShares(const cv::Mat &channel, cv::Mat &share1, cv::Mat &share2);


    void combineShares(const cv::Mat &share1R, const cv::Mat &share1G, const cv::Mat &share1B,
                       const cv::Mat &share2R, const cv::Mat &share2G, const cv::Mat &share2B,
                       cv::Mat &finalShare1, cv::Mat &finalShare2);

    void readData(std::vector<std::vector<int>> &myMat, int opt) override;

    void doEncryption() override;

    void doDecryption() override;
};


#endif //OOP_STRATEGYCOLOR_H
