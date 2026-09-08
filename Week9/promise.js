function NewPromise(executorFunction) {
  this.state = "pending";
  this.result = "";

  let successCallBack = null;
  let errorCallBack = null;

  const resolve = (value) => {
    if (this.state !== "pending") return;

    this.state = "fulfilled";
    this.result = value;

    if (successCallBack) {
      successCallBack(value);
    }
  };

  const reject = (error) => {
    if (this.state !== "pending") return;

    this.state = "rejected";
    this.result = error;

    if (errorCallBack) {
      errorCallBack(error);
    }
  };

  this.then = function (callback) {
    return new NewPromise((resolveNext, rejectNext) => {

      successCallBack = (value) => {
        try {
          const result = callback(value);
          resolveNext(result);
        } catch (error) {
          rejectNext(error);
        }
      };

      errorCallBack = (error) => {
        rejectNext(error);
      };

      if (this.state === "fulfilled") {
        successCallBack(this.result);
      }

      if (this.state === "rejected") {
        errorCallBack(this.result);
      }
    });
  };

  this.catch = function (callback) {
    return new NewPromise((resolveNext, rejectNext) => {

      errorCallBack = (error) => {
        try {
          const result = callback(error);
          resolveNext(result);
        } catch (err) {
          rejectNext(err);
        }
      };

      successCallBack = (value) => {
        resolveNext(value);
      };

      if (this.state === "fulfilled") {
        resolveNext(this.result);
      }

      if (this.state === "rejected") {
        errorCallBack(this.result);
      }
    });
  };

  try {
    executorFunction(resolve, reject);
  } catch (error) {
    reject(error);
  }
}

new NewPromise(resolve => {
  resolve(5);
})
.then(value => {
  return value * 2;
})
.then(value => {
  return value * 5;
})
.then(value => {
  console.log(value);
});