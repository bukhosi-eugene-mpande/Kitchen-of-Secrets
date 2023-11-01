# Backend API Requirements

## Introduction

This document outlines the requirements for the backend API that the frontend will rely on. It describes the endpoints, request parameters, and expected JSON responses for each endpoint.

## API Base URL

- Base URL: `https://api.example.com`

## Endpoints

### 1. Homepage

- **Endpoint:** `/Homepage`
- **Method:** GET

**Response:**

```json
{
  "Github": "https//github.com/username",
  "Documentatiom": "https//documentatiom.com",
  "Team": [
    {
      "name": "name",
      "email": "email",
      "github": "github"
    },
    {
      "name": "name",
      "email": "email",
      "github": "github"
    }
  
  ]
}
```

### 2. Manager page

- **Endpoint:** `/manager`
- **Method:** GET

**Response:**

```json
{
  "privatetables": [
    {
      "table_id": 1,
      "table_name": "table_name",
      "table_status": "table_status",
      "table_capacity": "table_capacity"
    },
    {
      "table_id": 2,
      "table_name": "table_name",
      "table_status": "table_status",
      "table_capacity": "table_capacity"
    }
  ],
  "generaltables" :[
    {
      "table_id": 1,
      "table_name": "table_name",
      "table_status": "table_status",
      "table_capacity": "table_capacity"
    },
    {
      "table_id": 2,
      "table_name": "table_name",
      "table_status": "table_status",
      "table_capacity": "table_capacity"
    }
  ],
  "Balance": "user123"

}
```

### 3. Ordering

- **Endpoint:** `/Ordering`
- **Method:** GET

**Response:**

```json
[
  {
    "item_id": 1,
    "name": "Item 1",
    "price": 19.99
  },
  {
    "item_id": 2,
    "name": "Item 2",
    "price": 29.99
  }
]
```
