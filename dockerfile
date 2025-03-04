FROM ubuntu:24.04

RUN apt update \
    && apt install vim -y \
    && apt install build-essential -y \
    && apt install check -y \
    && apt install libgtest-dev -y

WORKDIR /project

COPY . .

CMD ["bash"]
