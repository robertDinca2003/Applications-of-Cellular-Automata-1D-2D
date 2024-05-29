//
// Created by robert on 21.05.2024.
//

#include "StrategyColor.h"

void StrategyColor::generateChannelShares(const cv::Mat &channel, cv::Mat &share1, cv::Mat &share2) {
    share1 = cv::Mat(channel.size(), CV_8UC1);
    share2 = cv::Mat(channel.size(), CV_8UC1);

    ElementaryRule rule(30, channel.cols, channel.rows * 3 / 2 + 1);
    rule.GenerateToMaxDepth();

    for (int y = 0; y < channel.rows; ++y) {
        for (int x = 0; x < channel.cols; ++x) {
            int pixel = channel.at<uchar>(y, x);
            int randomBit = rule.getElement(y + channel.rows / 2, x);

            if (pixel < 128) { // Dark pixel
                if (randomBit == 0) {
                    share1.at<uchar>(y, x) = 0;
                    share2.at<uchar>(y, x) = 255;
                } else {
                    share1.at<uchar>(y, x) = 255;
                    share2.at<uchar>(y, x) = 0;
                }
            } else { // Light pixel
                if (randomBit == 0) {
                    share1.at<uchar>(y, x) = 0;
                    share2.at<uchar>(y, x) = 0;
                } else {
                    share1.at<uchar>(y, x) = 255;
                    share2.at<uchar>(y, x) = 255;
                }
            }
        }
    }
}


void StrategyColor::combineShares(const cv::Mat &share1R, const cv::Mat &share1G, const cv::Mat &share1B,
                                  const cv::Mat &share2R, const cv::Mat &share2G, const cv::Mat &share2B,
                                  cv::Mat &finalShare1, cv::Mat &finalShare2) {
    std::vector<cv::Mat> channels1 = {share1B, share1G, share1R};
    std::vector<cv::Mat> channels2 = {share2B, share2G, share2R};

    cv::merge(channels1, finalShare1);
    cv::merge(channels2, finalShare2);
}

void StrategyColor::readData(std::vector<std::vector<int>> &myMat, int opt) {

}

void StrategyColor::doEncryption() {
    cv::Mat image = cv::imread("colorInputEn.jpg");

    std::vector<cv::Mat> channels(3);
    cv::split(image, channels);

    cv::Mat share1R, share1G, share1B, share2R, share2G, share2B;

    generateChannelShares(channels[2], share1R, share2R);
    generateChannelShares(channels[1], share1G, share2G);
    generateChannelShares(channels[0], share1B, share2B);

    cv::Mat finalShare1, finalShare2;
    combineShares(share1R, share1G, share1B, share2R, share2G, share2B, finalShare1, finalShare2);

    cv::imwrite("colorOutput1De.png", finalShare1);
    cv::imwrite("colorOutput2De.png", finalShare2);
}

void StrategyColor::doDecryption() {
    cv::Mat finalShare1 = cv::imread("colorOutput1De.png");
    cv::Mat finalShare2 = cv::imread("colorOutput2De.png");
    cv::Mat decryptedImage;
    cv::addWeighted(finalShare1, 0.5, finalShare2, 0.5, 0, decryptedImage);
    cv::imwrite("colorOutputDe.png", decryptedImage);
}