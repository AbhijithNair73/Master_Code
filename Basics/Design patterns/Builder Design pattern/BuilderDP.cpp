https://digestcpp.com/designpattern/creational/builder/

/*
 * Example of `builder' design pattern.
 * Copyright (C) 2011 Radek Pazdera
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */


#include <iostream>
#include <string>

/* Car parts */
class Wheel
{
    public:
        int size;
};

class Engine
{
    public:
        int horsepower;
};

class Body
{
    public:
        std::string shape;
};

/* Final product -- a car */
class Car
{
    public:
        Wheel*   wheels[4];
        Engine*  engine;
        Body* body;
    
        void specifications()
        {
            std::cout << "body:" << body->shape << std::endl;
            std::cout << "engine horsepower:" << engine->horsepower << std::endl;
            std::cout << "tire size:" << wheels[0]->size << "'" << std::endl;
        }
};

/* Builder is responsible for constructing the smaller parts */
class Builder
{
    public:
        virtual Wheel* getWheel() = 0;
        virtual Engine* getEngine() = 0;
        virtual Body* getBody() = 0;
};

/* Director is responsible for the whole process */
class Director
{
    Builder* builder;

    public:
        void setBuilder(Builder* newBuilder)
        {
            builder = newBuilder;
        }

        Car* getCar()
        {
            Car* car = new Car();

            car->body = builder->getBody();

            car->engine = builder->getEngine();

            car->wheels[0] = builder->getWheel();
            car->wheels[1] = builder->getWheel();
            car->wheels[2] = builder->getWheel();
            car->wheels[3] = builder->getWheel();

            return car;
        }
};

/* Concrete Builder for Jeep SUV cars */
class JeepBuilder : public Builder
{
    public:
        Wheel* getWheel()
        {
            Wheel* wheel = new Wheel();
            wheel->size = 22;
            return wheel;
        }

        Engine* getEngine()
        {
            Engine* engine = new Engine();
            engine->horsepower = 400;
            return engine;
        }

        Body* getBody()
        {
            Body* body = new Body();
            body->shape = "SUV";
        }
};

/* Concrete builder for Nissan family cars */
class NissanBuilder : public Builder
{
    public:
        Wheel* getWheel()
        {
            Wheel* wheel = new Wheel();
            wheel->size = 16;
            return wheel;
        }

        Engine* getEngine()
        {
            Engine* engine = new Engine();
            engine->horsepower = 85;
            return engine;
        }

        Body* getBody()
        {
            Body* body = new Body();
            body->shape = "hatchback";
        }
};


int main()
{
    Car* car; // Final product

    /* A director who controls the process */
    Director director;

    /* Concrete builders */
    JeepBuilder jeepBuilder;
    NissanBuilder nissanBuilder;

    /* Build a Jeep */
    std::cout << "Jeep" << std::endl;
    director.setBuilder(&jeepBuilder); // using JeepBuilder instance
    car = director.getCar();
    car->specifications();

    std::cout << std::endl;

    /* Build a Nissan */
    std::cout << "Nissan" << std::endl;
    director.setBuilder(&nissanBuilder); // using NissanBuilder instance
    car = director.getCar();
    car->specifications();

    return 0;
}
