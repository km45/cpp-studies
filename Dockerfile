FROM gcc:latest

RUN apt-get update \
    && apt-get install -y --no-install-recommends \
        valgrind \
    && apt-get clean \
    && rm -rf /var/lib/apt/lists/*

CMD ["tail", "-f", "/dev/null"]
