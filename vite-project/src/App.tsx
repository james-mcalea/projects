import Button from "./components/Button";
import Alert from "./components/Alert";
import { useState } from "react";
function App() {
  const [alertVisible, setAlertVisibility] = useState(false);

  return (
    <div>
      {alertVisible && (
        <Alert onClose={() => setAlertVisibility(false)}>My alert</Alert>
      )}
      <Button colour="primary" onClick={() => setAlertVisibility(true)}>
        My button
      </Button>
    </div>
  );
}

export default App;
