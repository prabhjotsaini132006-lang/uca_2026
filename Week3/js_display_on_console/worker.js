self.onmessage = async (event) => {
    if (event.data !== "fetchUsers") {
        return;
    }

    try {
        const response = await fetch("https://dummyjson.com/users");

        if (!response.ok) {
            throw new Error("Failed to fetch users.");
        }

        const data = await response.json();

        if (!data.users || data.users.length === 0) {
            throw new Error("No users returned from the API.");
        }

        self.postMessage({
            success: true,
            users: data.users,
        });
    } catch (error) {
        self.postMessage({
            success: false,
            message: error.message,
        });
    }
};