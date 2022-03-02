#include "celanoc_stats.hpp"
#include <math.h>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

void celanoSpace::calebSpace::calebClass::calc_min (std::vector<float>* data) {
    float functempmin = 0;
    for (int i = 0; i <= data->size(); i++) {
        if (data->at(i) < functempmin) {
            functempmin = data->at(i);
        }
    }
    this->min = functempmin;
}

void celanoSpace::calebSpace::calebClass::calc_max (std::vector<float>* data) {
    float functempmax = 0;
    for (int i = 0; i <= data->size(); i++) {
        if (data->at(i) > functempmax) {
            functempmax = data->at(i);
        }
    }
    this->max = functempmax;
}

void celanoSpace::calebSpace::calebClass::calc_mean (std::vector<float>* data) {
    float functempmean = 0;
    float sum = 0;
    for (int i = 0; i <= data->size(); i++) {
        sum = sum + data->at(i);
    }
    functempmean = sum/data->size();
    this->mean = functempmean;
}

void celanoSpace::calebSpace::calebClass::calc_stdev (std::vector<float>* data) {
    float functempstdev = 0;
    float sum = 0;
    float temp = 0;
    float num = 0;
    for (int i = 0; i <= data->size(); i++) {
        num = data->at(i) - mean;
        sum = sum + (num * num);
    }
    temp = sum/(data->size() - 1);
    functempstdev = sqrt(temp);
    this->stdev = functempstdev;
}

/*void celanoSpace::calebSpace::calebClass::est_histo (std::vector<float>* data) {
    int i = 0;
    float binWidth = 0;
    binWidth = 0.4*stdev;

    float binBegin = 0;
    binBegin = mean-3*stdev;

    float binEnd = 0;
    binEnd = mean+3*stdev;

    float tempfrequencySize = 0;
    tempfrequencySize = (binEnd - binBegin)/binWidth;

    float tempbinLocationX[tempfrequencySize + 1];
    int frequency[tempfrequencySize + 1];
    int frequencyIndex = 0;

    float binLocation = 0;
    binLocation = binBegin;

    for (i = 0; binLocation <= binEnd; i++) {
        tempbinLocationX[i] = binLocation;
        binLocation = binLocation + binWidth;
    }

    for (i = 0; i < tempfrequencySize; i++) { 
        frequency[i] = 0;
    }

    for (i = 0; i < data->size(); i++) {
        frequencyIndex = 0;
        if (data->at(i) > binBegin) && (data->at(i) < binStop)) {
            frequencyIndex = (data->at(i) - binBegin)/binWidth;
        }
        else if (data[i] > binEnd) {
            frequencyIndex = tempfrequencySize;
        }
        ++frequency[frequencyIndex];
    }
    this->frequencySize = tempfrequencySize
    this->
}*/

float* celanoSpace::calebSpace::calebClass::get_min() {

    return &(this->min);
}

float* celanoSpace::calebSpace::calebClass::get_max() {

    return &(this->max);
}

float* celanoSpace::calebSpace::calebClass::get_mean() {

    return &(this->mean);
}

float* celanoSpace::calebSpace::calebClass::get_stdev() {

    return &(this->stdev);
}