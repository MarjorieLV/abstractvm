#include "factory.hpp"
#include "operand.hpp"

#include <iostream>
#include <string>


static void fillMap(Factory *self, Factory::ctorByType& toFill, eOperandType type, Factory::funcPtr factoryfunc)
{
    using namespace std::placeholders;
    Factory::funcObject toAdd = std::bind(factoryfunc, self, _1);
    toFill.insert( std::make_pair( type, toAdd));
}
Factory::Factory()
{

    fillMap(this, operandByType, eOperandType::INT8,   &Factory::createInt8);
    fillMap(this, operandByType, eOperandType::INT16,  &Factory::createInt16);
    fillMap(this, operandByType, eOperandType::INT32,  &Factory::createInt32);
    fillMap(this, operandByType, eOperandType::FLOAT,  &Factory::createFloat);
    fillMap(this, operandByType, eOperandType::DOUBLE, &Factory::createDouble);
}


IOperand const * Factory::createOperand( eOperandType type, std::string const & value ) const
{

    auto it = operandByType.find(type);
    if (it != operandByType.end()) {
        auto ctor = it->second;
        // if()
        return ctor(value);
    }
    return nullptr;
}

IOperand const * Factory::createInt8( std::string const & value ) const
{
    std::cout << "create Int8 \n";
    IOperand const * newInt8 = new Operand( eOperandType::INT8, value);
    return newInt8;
}

IOperand const * Factory::createInt16( std::string const & value ) const
{
    std::cout << "create Int16 \n";
    IOperand const * newInt16 = new Operand(eOperandType::INT16, value);
    return newInt16;
}

IOperand const * Factory::createInt32( std::string const & value ) const
{
    std::cout << "create Int32 \n";
    IOperand const * newInt32 = new Operand(eOperandType::INT32, value);
    return newInt32;
}

IOperand const * Factory::createFloat( std::string const & value ) const
{
    std::cout << "create Float \n";
    IOperand const * newFloat = new Operand(eOperandType::FLOAT, value);
    return newFloat;
}

IOperand const * Factory::createDouble( std::string const & value ) const
{
    std::cout << "create Double \n";
    IOperand const * newDouble = new Operand(eOperandType::DOUBLE, value);
    return newDouble;
}
