CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -pedantic -g -MMD -MP

TARGET := programa

SRCS := $(wildcard *.cpp) $(wildcard *.cc)

OBJS := $(patsubst %.cpp, %.o, $(patsubst %.cc, %.o, $(SRCS)))

DEPS := $(OBJS:.o=.d)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

%.o: %.cc
	$(CXX) $(CXXFLAGS) -c $< -o $@

-include $(DEPS)

clean:
	rm -f $(OBJS) $(DEPS) $(TARGET)

.PHONY: all clean