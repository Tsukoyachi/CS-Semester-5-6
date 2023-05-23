all: build

build:
	docker build -t node-app .

run:
	docker run -p 8888:8080 -v /etc/timezone:/etc/timezone:ro -v /etc/localdate:/etc/localdate:ro node-app

clean:
	docker images -a | grep none | awk '{ print $$3; }' | xargs -t 2>/dev/null docker rmi

mrproper: clean
	rm -r node_modules
