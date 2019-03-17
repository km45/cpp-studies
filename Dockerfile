FROM alpine:3.9.2

RUN apk update \
    && apk add \
        bash \
        cmake \
        g++ \
        git \
        make \
        ninja \
        valgrind \
    && rm -rf /var/cache/apk/*

CMD ["tail", "-f", "/dev/null"]
