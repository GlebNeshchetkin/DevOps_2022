FROM gcc:latest
COPY . /usr/src/dockertest1
WORKDIR /usr/src/dockertest1
RUN g++ -o Test *.cpp
CMD [ "./Test" ]
