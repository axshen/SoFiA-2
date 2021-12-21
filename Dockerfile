FROM ubuntu:20.04
WORKDIR /app

# Install dependencies
RUN apt-get update && \
    apt-get install -y build-essential wcslib-dev

# Install sofia
COPY . .
RUN ./compile.sh -fopenmp &&\
    ln -s /app/sofia /usr/bin/sofia

ENTRYPOINT ["sofia"];