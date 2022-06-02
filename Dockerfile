FROM gcc:latest
COPY . /usr/src/dockertest1
WORKDIR /usr/src/dockertest1
RUN g++ -o Test main.cpp Engineer.cpp Employee.cpp Manager.cpp Factory.cpp Personal.cpp
CMD [ "./Test" ]
