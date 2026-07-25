const worker = new Worker("worker.js");

worker.postMessage("fetchUsers");

worker.onmessage = (event) => {
    const data = event.data;

    if (data.success) {
        data.users.forEach((user) => {
            const status = user.role === "user" ? "Inactive" : "Active";
            console.log(`${user.firstName} ${user.lastName} - ${status}`);
        });
    } else {
        console.error(data.message);
    }
};

worker.onerror = (error) => {
    console.error("Worker Error:", error.message);
};