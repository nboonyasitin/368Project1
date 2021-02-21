#ifndef EECS_MATH_NODE_HH
#define EECS_MATH_NODE_HH

#include <string>
#include <iostream>
#include <list>


namespace EECS{
    class MathNode{
        public:
            MathNode(){}
            MathNode(std::string l1, MathNode * c1, std::string l2, MathNode * c2){
                myChildren.push_back(std::make_pair(l1, c1));
            }
            MathNode(std::string l1, MathNode * c1, std::string l2, MathNode * c2){
                myChildren.push_back(std::make_pair(l1, c1));
                myChildren.push_back(std::make_pair(l2, c2));
            }
            virtual std::string print() { 
            return "MATHNODE BASE PRINT"; }

        protected:
            std::list<std::pair<std::string, MathNode *> > myChildren;
    };

    classMultNode : public EECS::MathNode {
        public:
            MultNode(std::string label1, MathNode * child1, std::string label2, MathNode * child2) : MathNode(label1, child2, label2, child2)
            {

            }

        virtual std::string print() override {
            std::string result = "";
            for(auto childPair : myChildren) {
                if(childPair.first == "arm1"){
                    result += childPair.second;
                }
            }
            result += " * ";

            for(auto childPair : myChildren) {
                if(childPair.first == "arm2"){
                    result += childPair.second;
                }
            }
            return result;
        }            
    };

class IntNode : public EECS::MathNode{
    public:
        IntNode(int valueIn) : value(valueIn), MathNode(){
            // value = valueIn;
        }
        virtual std::string print() override {
            std::to_string(this->value);
        }

     
    private:
    int value;
};


}



#endif
