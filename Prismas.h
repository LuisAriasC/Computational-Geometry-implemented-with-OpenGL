//
//  Prismas.h
//  EjerciciosOpenGL
//
//  Created by Omar Arias on 3/11/17.
//  Copyright © 2017 Omar Arias. All rights reserved.
//
#include "Poligon.h"

#ifndef Prismas_h
#define Prismas_h


vector<pair<float, float> > c1; //Cuadrado 1 de frente
vector<pair<float, float> > c2; //Cuadrado 2 atrás

vector<pair<float, float> > cc1; //Cuadrado 1 de frente
vector<pair<float, float> > cc2; //Cuadrado 2 atrás

vector<float> an;
vector<float> an1;

GLdouble lado =  (width * .40); //Radio del cuadrado
GLdouble radius_c = (lado/2);

float angle_increment = 360 / 4; //Incremento en grados
float angle_rectangle = 360 / 6;
float inc_rad = angle_increment * (M_PI/180); //incremento en radianes
float angle_rad = 0.00; //inicio de angulo en radianes
float angle_lad = inc_rad/2;
float lado_radio_x = radius_c * cos(angle_lad);
float lado_x = 2 * lado_radio_x;
float lado_sup_x = lado_x / 3;
float cx1 = 0.0, cy1 = 0.0, cx2 , cy2;
float ccx1 = 0.0, ccy1 = 0.0, ccx2 , ccy2;

void print_Prisma1(int pr){
    pair<float, float> p;
    
    cx2 = cx1 + lado_sup_x; cy2 = cy1 + lado_sup_x;
    if (refle == true) {
        ccx2 = ccx1 + lado_sup_x; ccy2 = ccy1 + lado_sup_x;
    }
    
    if (pr == 1 || pr == 2) {
        //plot(cx1,cy1); //Referencia centro del plano; CUADRADO1
        //plot(cx2, cy2);
        if (pr == 2) {
            an.push_back(  angle_rectangle * (M_PI/180));
            an.push_back(2*angle_rectangle * (M_PI/180));
            an.push_back(4*angle_rectangle * (M_PI/180));
            an.push_back(5*angle_rectangle * (M_PI/180));
            if (refle == true) {
                an1.push_back(  angle_rectangle * (M_PI/180));
                an1.push_back(2*angle_rectangle * (M_PI/180));
                an1.push_back(4*angle_rectangle * (M_PI/180));
                an1.push_back(5*angle_rectangle * (M_PI/180));
            }
        }
        for (int i=0; i<4; i++) {
            if(i!=0){
                if (pr == 1) {
                    angle_rad += inc_rad;
                    an.push_back(angle_rad);
                    if (refle == true) {
                        an1.push_back(angle_rad);
                    }
                }
                p.first = cx1 + (radius_c * cos(an[i])); p.second = cy1 + (radius_c *  sin(an[i]));
                c1.push_back(p);
                if (refle == true) {
                    p.first = ccx1 + (radius_c * cos(an[i])); p.second = ccy1 + (radius_c *  sin(an1[i]));
                    cc1.push_back(p);
                }
                
                p.first = cx2 + (radius_c * cos(an[i])); p.second = cy2 + (radius_c *  sin(an[i]));
                c2.push_back(p);
                if (refle == true) {
                    p.first = ccx2 + (radius_c * cos(an[i])); p.second = ccy2 + (radius_c *  sin(an1[i]));
                    cc2.push_back(p);
                }
                //plot(c1[i].first, c1[i].second);
                //plot(c2[i].first, c2[i].second);
            }
            else{
                if (pr == 1) {
                    angle_rad += angle_lad;
                    an.push_back(angle_rad);
                    if (refle == true) {
                        an1.push_back(angle_rad);
                    }
                }
                p.first = cx1 + (radius_c * cos(an[i])); p.second = cy1 + (radius_c *  sin(an[i]));
                c1.push_back(p);
                if (refle == true) {
                    p.first = ccx1 + (radius_c * cos(an[i])); p.second = ccy1 + (radius_c *  sin(an1[i]));
                    cc1.push_back(p);
                }
                p.first = cx2 + (radius_c * cos(an[i])); p.second = cy2 + (radius_c *  sin(an[i]));
                c2.push_back(p);
                if (refle == true) {
                    p.first = ccx2 + (radius_c * cos(an[i])); p.second = ccy2 + (radius_c *  sin(an1[i]));
                    cc2.push_back(p);
                }
                //plot(c1[i].first, c1[i].second);
                //plot(c2[i].first, c2[i].second);
            }
        }
        
        if (c1.size() > 4) {
            for (int i = c1.size(); i > 4; i--) {
                c1.pop_back(); c2.pop_back(); an.pop_back();
                if (refle==true) {
                    cc1.pop_back(); cc2.pop_back(); an1.pop_back();
                }
            }
        }
    }
    if (pr==3) {
        for (int i=0; i<3; i++) {
            if(i!=0){
                angle_rad += inc_rad;
                an.push_back(angle_rad);
                if (refle == true) {
                    an1.push_back(angle_rad);
                }
                p.first = cx1 + (radius_c * cos(an[i])); p.second = cy1 + (radius_c *  sin(an[i]));
                c1.push_back(p);
                if (refle == true) {
                    p.first = ccx1 + (radius_c * cos(an[i])); p.second = ccy1 + (radius_c *  sin(an1[i]));
                    cc1.push_back(p);
                }
                
                p.first = cx2 + (radius_c * cos(an[i])); p.second = cy2 + (radius_c *  sin(an[i]));
                c2.push_back(p);
                if (refle == true) {
                    p.first = ccx2 + (radius_c * cos(an[i])); p.second = ccy2 + (radius_c *  sin(an1[i]));
                    cc2.push_back(p);
                }
                //plot(c1[i].first, c1[i].second);
                //plot(c2[i].first, c2[i].second);
            }
            else{
                angle_rad += angle_lad;
                an.push_back(angle_rad);
                if (refle == true) {
                    an1.push_back(angle_rad);
                }
                
                p.first = cx1 + (radius_c * cos(an[i])); p.second = cy1+ (radius_c *  sin(an[i]));
                c1.push_back(p);
                if (refle == true) {
                    p.first = ccx1 + (radius_c * cos(an[i])); p.second = ccy1 + (radius_c *  sin(an1[i]));
                    cc1.push_back(p);
                }
                
                p.first = cx2 + (radius_c * cos(an[i])); p.second = cy2 + (radius_c *  sin(an[i]));
                c2.push_back(p);
                if (refle == true) {
                    p.first = ccx2 + (radius_c * cos(an[i])); p.second = ccy2 + (radius_c *  sin(an1[i]));
                    cc2.push_back(p);
                }
                //plot(c1[i].first, c1[i].second);
                //plot(c2[i].first, c2[i].second);
            }
            if (c1.size() > 3) {
                for (int i = c1.size(); i > 3; i--) {
                    c1.pop_back(); c2.pop_back(); an.pop_back();
                    if (refle==true) {
                        cc1.pop_back(); cc2.pop_back(); an1.pop_back();
                    }
                }
            }
        }
    }
    
    for (int i = 0; i < c1.size(); i++) {
        if (i<=c1.size()-2) {
            DDA_Line(c1[i].first, c1[i].second, c1[i+1].first, c1[i+1].second);
            DDA_Line(c2[i].first, c2[i].second, c2[i+1].first, c2[i+1].second);
            if (refle==true) {
                DDA_Line(cc1[i].first, cc1[i].second, cc1[i+1].first, cc1[i+1].second);
                DDA_Line(cc2[i].first, cc2[i].second, cc2[i+1].first, cc2[i+1].second);
            }
        }
        if (i == c1.size()-1) {
            DDA_Line(c1[i].first, c1[i].second, c1[0].first, c1[0].second);
            DDA_Line(c2[i].first, c2[i].second, c2[0].first, c2[0].second);
            if (refle==true) {
                DDA_Line(cc1[i].first, cc1[i].second, cc1[0].first, cc1[0].second);
                DDA_Line(cc2[i].first, cc2[i].second, cc2[0].first, cc2[0].second);
            }
        }
        DDA_Line(c1[i].first, c1[i].second, c2[i].first, c2[i].second);
        if (refle==true) {
            DDA_Line(cc1[i].first, cc1[i].second, cc2[i].first, cc2[i].second);
        }
    }
}

float xcon = 0.0, ycon = 0.0;
float rad_con = (height / 100.00) * 50.00;
float inc_con = 90.00 * (M_PI/180);
float inc_start = 0.00;
float inc_ellip = 270.00 * (M_PI/180);
vector<pair<float, float> > el;

void print_Cone(void){
    plot(xcon, ycon);
    float top_x = xcon + (rad_con * cos(inc_con));
    float top_y = ycon + (rad_con * sin(inc_con));
    float x_ell = xcon + (rad_con * cos(inc_ellip));
    float y_ell = ycon + (rad_con * sin(inc_ellip));
    
    pair<float, float> p;
    
    //plot(top_x,top_y);
    //plot(x_ell, y_ell);

    float xe1 = x_ell + (rad_con * cos(inc_start)), xe2 = x_ell - (rad_con * cos(inc_start));
    float ye1 = y_ell + (rad_con * sin(inc_start)), ye2 = y_ell + (rad_con * sin(inc_start));
    
    //plot(xe1, ye1);
    //plot(xe2, ye2);
    
    DDA_Line(top_x, top_y, xe1, ye1);
    DDA_Line(top_x, top_y, xe2, ye2);
    
    //DDA_Line(el[0].first, el[0].second, el[1].first, el[1].second);
    //DDA_Line(el[0].first, el[0].second, el[2].first, el[2].second);
    xel = x_ell; yel = y_ell;
    ellipse(rad_con * cos(inc_start) , (rad_con * cos(inc_start))/2);
}



#endif /* Prismas_h */
