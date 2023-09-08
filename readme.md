# C-Programming start project

## Database Setup

### required software
We use [podman](https://podman.io/), [minikube](https://minikube.sigs.k8s.io/docs/) and [kubectl](https://kubernetes.io/docs/tasks/tools/) for running our postgresql database.
Be sure to also install [kubectl autocompletion](https://kubernetes.io/docs/tasks/tools/install-kubectl-macos/#enable-shell-autocompletion) or [kubectl completion for windows](https://kubernetes.io/docs/tasks/tools/install-kubectl-windows/)

For windows make sure that you install windows terminal from the Microsoft Store
```bash
winget install Microsoft.WindowsTerminal
```

### setup your environment (once)
```bash
podman machine init
podman machine set --rootful
podman machine start
minikube --driver=podman start
minikube stop
podman machine stop
```

### initialize podman and start minikube after your computer has restarted:

```bash
podman machine start
minikube start
```
### install a postgresql database

in a terminal change to the k8s/podman subfolderfolder and run:
```bash
kubectl apply -f postgresql.yaml
kubectl get pods
kubectl port-forward pos<tab>-<tab> 5432:5432
minikube dashboard
```
...<tab>-<tab> means to press the tab key twice, fast for kubectl autompletion. Otherwise copy the name of the postgres pod from the command line. 


remove the database again:
```bash
kubectl delete -f postgresql.yaml
```

### troubeshooting

In case of problems try to prune your system. Stop all containers and then:
```bash
podman system prune
```

in the case tah your problems continue ou can do a fresh start by removing all data:
```bash
minikube stop
minikube delete
podman machine stop
podman machine rm podman-machine-default
```
... and then initialize the system from scratch again

## Database client program

Download [DBeaver](https://dbeaver.io/) and connect with a postgresql driver to localhost:5432 username and password can be seen in the postgresql.yaml file
