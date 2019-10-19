FROM ubuntu:16.04

RUN apt-get update \
    && apt-get install -y g++-powerpc64-linux-gnu \
    && apt-get clean \
    && rm -rf /var/lib/apt/lists/*

CMD ["tail", "-f", "/dev/null"]
