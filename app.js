// Load content into element with given ID
function loadText(filePath, elementId) {
  fetch(filePath)
    .then(response => {
      if (!response.ok) throw new Error("File not found: " + filePath);
      return response.text();
    })
    .then(data => {
      document.getElementById(elementId).innerHTML = data;
    })
    .catch(err => {
      document.getElementById(elementId).innerHTML = `<p style="color:red;">${err}</p>`;
    });
}

// Load each file into its container
loadText('texts/intro.txt', 'intro-text');
loadText('texts/explanation.txt', 'explanation-text');
loadText('texts/table.txt', 'table-text');

// Load inputs into containers
loadText('texts/defaultInput.txt', 'ls-input');
loadText('texts/defaultInput.txt', 'bs-input');

function loadDefaultCode(filePath, textareaId) {
  fetch(filePath)
    .then(response => {
      if (!response.ok) throw new Error("File not found: " + filePath);
      return response.text();
    })
    .then(data => {
      document.getElementById(textareaId).value = data;
    })
    .catch(err => {
      document.getElementById(textareaId).value = `Error loading code: ${err}`;
    });
}

//load code into container
loadDefaultCode('codes/Linear_search.cpp', 'ls-code');
loadDefaultCode('codes/Binary_search.cpp', 'bs-code');

async function runCode(inputId, codeId, outputId) {
  const sourceCode = document.getElementById(codeId).value;
  const inputText = document.getElementById(inputId).value; // User input for cin

  const requestBody = {
    source_code: sourceCode,
    language_id: 76, // C++ (GCC 9.2.0)
    stdin: inputText
  };

  const response = await fetch("https://judge0-ce.p.rapidapi.com/submissions?base64_encoded=false&wait=true", {
    method: "POST",
    headers: {
      "Content-Type": "application/json",
      "X-RapidAPI-Key": "068d539501mshea54bf1b9ffd79ep18932cjsn6aa15b329dc1",
      "X-RapidAPI-Host": "judge0-ce.p.rapidapi.com"
    },
    body: JSON.stringify(requestBody)
  });

  const result = await response.json();
  document.getElementById(outputId).textContent =
    result.stdout || result.stderr || result.compile_output || "No output.";
}