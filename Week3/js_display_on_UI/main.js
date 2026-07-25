const worker = new Worker("worker.js");

const divUsers = document.getElementById("users");

worker.postMessage("fetchUsers");

worker.onmessage = (event) => {
    const data = event.data;

    if (data.success) {
        divUsers.innerHTML = "";

        data.users.forEach((user) => {
            const userElement = document.createElement("li");
            const status = user.role === "user" ? "Inactive" : "Active";

            userElement.textContent =
                `${user.firstName} ${user.lastName} - ${status}`;

            divUsers.appendChild(userElement);
        });
    } else {
        divUsers.textContent = data.message;
    }
};

worker.onerror = (error) => {
    divUsers.textContent = "Worker Error: " + error.message;
};