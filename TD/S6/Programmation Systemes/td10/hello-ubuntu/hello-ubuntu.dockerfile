FROM ubuntu-22.04
COPY hello .
RUN make
CMD ["./hello"]