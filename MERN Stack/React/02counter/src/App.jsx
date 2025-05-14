import { useState } from "react";

import "./App.css";

function App() {
  let [counter, setCounter] = useState(15);

  // let counter = 5;

  const addValue = () => {
    if (counter < 20) setCounter((prevCounter) => prevCounter + 1);
  };

  const removeValue = () => {
    if (counter > 0) setCounter((prevCounter) => prevCounter - 1);
  };

  return (
    <>
      <h1>Chai aur react</h1>
      <h2>Counter value: {counter}</h2>

      <button onClick={addValue}>Add Value</button>
      <br />
      <button onClick={removeValue}>Remove Value</button>
    </>
  );
}

export default App;
