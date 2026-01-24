import React, { useState } from 'react';

const SignInPage = () => {
  const [email, setEmail] = useState('');
  const [password, setPassword] = useState('');
  const [error, setError] = useState('');
  const [isLoggedIn, setIsLoggedIn] = useState(false);

  const VALID_EMAIL = "user@example.com";
  const VALID_PASSWORD = "password123";

  
  const handleSubmit = (e) => {
    e.preventDefault();
    if (email === VALID_EMAIL && password === VALID_PASSWORD) {
      setIsLoggedIn(true);
      setError('');
    } else {
      setError('Invalid email or password.');
    }
  };

  if (isLoggedIn) {
    return (
      <div style={styles.container}>
        <div style={styles.card}>
          <h1>Success!</h1>
          <p>You are now signed in.</p>
          <button onClick={() => setIsLoggedIn(false)} style={styles.button}>
            Logout
          </button>
        </div>
      </div>
    );
  }

  return (
    <div style={styles.container}>
      <div style={styles.card}>
        <h2 style={styles.title}>Sign In</h2>
        <form onSubmit={handleSubmit}>
          <div style={styles.inputGroup}>
            <label style={styles.label}>Email Address</label>
            <input
              type="email"
              style={styles.input}
              value={email}
              onChange={(e) => setEmail(e.target.value)}
              required
            />
          </div>
          <div style={styles.inputGroup}>
            <label style={styles.label}>Password</label>
            <input
              type="password"
              style={styles.input}
              value={password}
              onChange={(e) => setPassword(e.target.value)}
              required
            />
          </div>
          {error && <p style={styles.error}>{error}</p>}
          <button type="submit" style={styles.button}>
            Sign In
          </button>
        </form>
      </div>
    </div>
  );
};

const styles = {
  container: {
    display: 'flex',
    justifyContent: 'center',
    alignItems: 'center',
    height: '100vh',
    backgroundColor: '#f4f7f6',
    fontFamily: 'Arial, sans-serif',
  },
  card: {
    backgroundColor: '#fff',
    padding: '40px',
    borderRadius: '8px',
    boxShadow: '0 4px 12px rgba(0,0,0,0.1)',
    width: '100%',
    maxWidth: '400px',
    textAlign: 'center',
  },
  title: {
    marginBottom: '20px',
    color: '#333',
  },
  inputGroup: {
    marginBottom: '15px',
    textAlign: 'left',
  },
  label: {
    display: 'block',
    marginBottom: '5px',
    fontSize: '14px',
    color: '#666',
  },
  input: {
    width: '100%',
    padding: '10px',
    boxSizing: 'border-box',
    borderRadius: '4px',
    border: '1px solid #ccc',
    fontSize: '16px',
  },
  button: {
    width: '100%',
    padding: '12px',
    backgroundColor: '#007bff',
    color: '#fff',
    border: 'none',
    borderRadius: '4px',
    fontSize: '16px',
    cursor: 'pointer',
    marginTop: '10px',
  },
  error: {
    color: 'red',
    fontSize: '13px',
    marginBottom: '10px',
  },
};

export default SignInPage;